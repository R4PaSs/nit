# This file is part of NIT ( http://www.nitlanguage.org ).
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# Services for byte streams and arrays
module bytes

import kernel
import collection::array
intrude import text::flat

# Any kind of entity which can be searched for in a Sequence of Byte
interface BytePattern
	# Return the first occurence of `self` in `b`, or -1 if not found
	fun first_index_in(b: SequenceRead[Byte]): Int do return first_index_in_from(b, 0)

	# Return the first occurence of `self` in `b` starting at `from`, or -1 if not found
	fun first_index_in_from(b: SequenceRead[Byte], from: Int): Int is abstract

	# Return the last occurence of `self` in `b`, or -1 if not found
	fun last_index_in(b: SequenceRead[Byte]): Int do return last_index_in_from(b, b.length - 1)

	# Return the last occurence of `self` in `b`, or -1 if not found
	fun last_index_in_from(b: SequenceRead[Byte], from: Int): Int is abstract

	# Returns the indexes of all the occurences of `self` in `b`
	fun search_all_in(b: SequenceRead[Byte]): SequenceRead[Int] is abstract

	# Length of the pattern
	fun pattern_length: Int is abstract

	# Appends `self` to `b`
	fun append_to(b: Sequence[Byte]) is abstract

	# Is `self` a prefix for `b` ?
	fun is_prefix(b: SequenceRead[Byte]): Bool is abstract

	# Is `self` a suffix for `b` ?
	fun is_suffix(b: SequenceRead[Byte]): Bool is abstract
end

redef class Byte
	super BytePattern

	# Write self as a string into `ns` at position `pos`
	private fun add_digest_at(ns: NativeString, pos: Int) do
		var tmp = (0xF0u8 & self) >> 4
		ns[pos] = if tmp >= 0x0Au8 then tmp + 0x37u8 else tmp + 0x30u8
		tmp = 0x0Fu8 & self
		ns[pos + 1] = if tmp >= 0x0Au8 then tmp + 0x37u8 else tmp + 0x30u8
	end

	# Is `self` a valid hexadecimal digit (in ASCII)
	#
	# ~~~nit
	# intrude import core::bytes
	# assert not '/'.ascii.is_valid_hexdigit
	# assert '0'.ascii.is_valid_hexdigit
	# assert '9'.ascii.is_valid_hexdigit
	# assert not ':'.ascii.is_valid_hexdigit
	# assert not '@'.ascii.is_valid_hexdigit
	# assert 'A'.ascii.is_valid_hexdigit
	# assert 'F'.ascii.is_valid_hexdigit
	# assert not 'G'.ascii.is_valid_hexdigit
	# assert not '`'.ascii.is_valid_hexdigit
	# assert 'a'.ascii.is_valid_hexdigit
	# assert 'f'.ascii.is_valid_hexdigit
	# assert not 'g'.ascii.is_valid_hexdigit
	# ~~~
	private fun is_valid_hexdigit: Bool do
		return (self >= 0x30u8 and self <= 0x39u8) or
		       (self >= 0x41u8 and self <= 0x46u8) or
		       (self >= 0x61u8 and self <= 0x66u8)
	end

	# `self` as a hexdigit to its byte value
	#
	# ~~~nit
	# intrude import core::bytes
	# assert 0x39u8.hexdigit_to_byteval == 0x09u8
	# assert 0x43u8.hexdigit_to_byteval == 0x0Cu8
	# ~~~
	#
	# REQUIRE: `self.is_valid_hexdigit`
	private fun hexdigit_to_byteval: Byte do
		if self >= 0x30u8 and self <= 0x39u8 then
			return self - 0x30u8
		else if self >= 0x41u8 and self <= 0x46u8 then
			return self - 0x37u8
		else if self >= 0x61u8 and self <= 0x66u8 then
			return self - 0x57u8
		end
		# Happens only if the requirement is not met.
		# i.e. this abort is here to please the compiler
		abort
	end

	redef fun first_index_in_from(b, from) do
		for i in [from .. b.length[ do if b[i] == self then return i
		return -1
	end

	redef fun last_index_in_from(b, from) do
		for i in [0 .. from].step(-1) do if b[i] == self then return i
		return -1
	end

	redef fun search_all_in(b) do
		var ret = new Array[Int]
		var pos = 0
		loop
			pos = first_index_in_from(b, pos)
			if pos == -1 then return ret
			ret.add pos
			pos += 1
		end
	end

	redef fun pattern_length do return 1

	redef fun append_to(b) do b.push self

	#     assert 'b'.ascii.is_suffix("baqsdb".to_bytes)
	#     assert not 'b'.ascii.is_suffix("baqsd".to_bytes)
	redef fun is_suffix(b) do return b.length != 0 and b.last == self

	#     assert 'b'.ascii.is_prefix("baqsdb".to_bytes)
	#     assert not 'b'.ascii.is_prefix("aqsdb".to_bytes)
	redef fun is_prefix(b) do return b.length != 0 and b.first == self
end

# A buffer containing Byte-manipulation facilities
#
# Uses Copy-On-Write when persisted
class Bytes
	super AbstractArray[Byte]
	super BytePattern

	# A NativeString being a char*, it can be used as underlying representation here.
	var items: NativeString

	# Number of bytes in the array
	redef var length

	# Capacity of the array
	private var capacity: Int

	# Has this buffer been persisted (to_s'd)?
	#
	# Used for Copy-On-Write
	private var persisted = false

	#     var b = new Bytes.empty
	#     assert b.to_s == ""
	init empty do
		var ns = new NativeString(0)
		init(ns, 0, 0)
	end

	# Init a `Bytes` with capacity `cap`
	init with_capacity(cap: Int) do
		var ns = new NativeString(cap)
		init(ns, 0, cap)
	end

	redef fun pattern_length do return length

	redef fun is_empty do return length == 0

	#     var b = new Bytes.empty
	#     b.add 101u8
	#     assert b[0] == 101u8
	redef fun [](i) do
		assert i >= 0
		assert i < length
		return items[i]
	end

	# Returns a copy of `self`
	fun clone: Bytes do
		var b = new Bytes.with_capacity(length)
		b.append(self)
		return b
	end

	# Trims off the whitespaces at the beginning and the end of `self`
	#
	#     var b = "102041426E6F1020" .hexdigest_to_bytes
	#     assert b.trim.hexdigest == "41426E6F"
	#
	# NOTE: A whitespace is defined here as a byte whose value is <= 0x20
	fun trim: Bytes do
		var st = 0
		while st < length do
			if self[st] > 0x20u8 then break
			st += 1
		end
		if st >= length then return new Bytes.empty
		var ed = length - 1
		while ed > 0 do
			if self[ed] > 0x20u8 then break
			ed -= 1
		end
		return slice(st, ed - st + 1)
	end

	# Returns a subset of the content of `self` starting at `from` and of length `count`
	#
	#     var b = "abcd".to_bytes
	#     assert b.slice(1, 2).hexdigest == "6263"
	#     assert b.slice(-1, 2).hexdigest == "61"
	#     assert b.slice(1, 0).hexdigest == ""
	#     assert b.slice(2, 5).hexdigest == "6364"
	fun slice(from, count: Int): Bytes do
		if count <= 0 then return new Bytes.empty

		if from < 0 then
			count += from
			if count < 0 then count = 0
			from = 0
		end

		if (count + from) > length then count = length - from
		if count <= 0 then return new Bytes.empty

		var ret = new Bytes.with_capacity(count)

		ret.append_ns(items.fast_cstring(from), count)
		return ret
	end

	# Returns a copy of `self` starting at `from`
	#
	#     var b = "abcd".to_bytes
	#     assert b.slice_from(1).hexdigest  == "626364"
	#     assert b.slice_from(-1).hexdigest == "61626364"
	#     assert b.slice_from(2).hexdigest  == "6364"
	fun slice_from(from: Int): Bytes do
		if from >= length then return new Bytes.empty
		if from < 0 then from = 0
		return slice(from, length)
	end

	# Returns self as a hexadecimal digest
	fun hexdigest: String do
		var elen = length * 2
		var ns = new NativeString(elen)
		var i = 0
		var oi = 0
		while i < length do
			self[i].add_digest_at(ns, oi)
			i += 1
			oi += 2
		end
		return new FlatString.full(ns, elen, elen)
	end

	#     var b = new Bytes.with_capacity(1)
	#     b[0] = 101u8
	#     assert b.to_s == "e"
	redef fun []=(i, v) do
		if persisted then regen
		assert i >= 0
		assert i <= length
		if i == length then add(v)
		items[i] = v
	end

	#     var b = new Bytes.empty
	#     b.add 101u8
	#     assert b.to_s == "e"
	redef fun add(c) do
		if persisted then regen
		if length >= capacity then
			enlarge(length)
		end
		items[length] = c
		length += 1
	end

	# Adds the UTF-8 representation of `c` to `self`
	#
	#     var b = new Bytes.empty
	#     b.add_char('A')
	#     b.add_char('キ')
	#     assert b.hexdigest == "41E382AD"
	fun add_char(c: Char) do
		if persisted then regen
		var cln = c.u8char_len
		var ln = length
		enlarge(ln + cln)
		items.set_char_at(length, c)
		length += cln
	end

	#     var b = new Bytes.empty
	#     b.append([104u8, 101u8, 108u8, 108u8, 111u8])
	#     assert b.to_s == "hello"
	redef fun append(arr) do
		if arr isa Bytes then
			append_ns(arr.items, arr.length)
		else
			for i in arr do add i
		end
	end

	#     var b = new Bytes.empty
	#     b.append([0x41u8, 0x41u8, 0x18u8])
	#     b.pop
	#     assert b.to_s == "AA"
	redef fun pop do
		assert length >= 1
		length -= 1
		return items[length]
	end

	redef fun clear do length = 0

	# Regenerates the buffer, necessary when it was persisted
	private fun regen do
		var nns = new NativeString(capacity)
		items.copy_to(nns, length, 0, 0)
		persisted = false
	end

	# Appends the `ln` first bytes of `ns` to self
	fun append_ns(ns: NativeString, ln: Int) do
		if persisted then regen
		var nlen = length + ln
		if nlen > capacity then enlarge(nlen)
		ns.copy_to(items, ln, 0, length)
		length += ln
	end

	# Appends `ln` bytes from `ns` starting at index `from` to self
	fun append_ns_from(ns: NativeString, ln, from: Int) do
		if persisted then regen
		var nlen = length + ln
		if nlen > capacity then enlarge(nlen)
		ns.copy_to(items, ln, from, length)
		length += ln
	end

	# Appends the bytes of `s` to `selftextextt`
	fun append_text(s: Text) do
		for i in s.substrings do
			append_ns(i.fast_cstring, i.bytelen)
		end
	end

	redef fun append_to(b) do b.append self

	redef fun enlarge(sz) do
		if capacity >= sz then return
		persisted = false
		while capacity < sz do capacity = capacity * 2 + 2
		var ns = new NativeString(capacity)
		items.copy_to(ns, length, 0, 0)
		items = ns
	end

	redef fun to_s do
		persisted = true
		var b = self
		var r = b.items.to_s_with_length(length)
		if r != items then persisted = false
		return r
	end

	redef fun iterator do return new BytesIterator.with_buffer(self)

	redef fun first_index_in_from(b, from) do
		if is_empty then return -1
		var fst = self[0]
		var bpos = fst.first_index_in_from(self, from)
		for i in [0 .. length[ do
			if self[i] != b[bpos] then return first_index_in_from(b, bpos + 1)
			bpos += 1
		end
		return bpos
	end

	redef fun last_index_in_from(b, from) do
		if is_empty then return -1
		var lst = self[length - 1]
		var bpos = lst.last_index_in_from(b, from)
		for i in [0 .. length[.step(-1) do
			if self[i] != b[bpos] then return last_index_in_from(b, bpos - 1)
			bpos -= 1
		end
		return bpos
	end

	redef fun search_all_in(b) do
		var ret = new Array[Int]
		var pos = first_index_in_from(b, 0)
		if pos == -1 then return ret
		pos = pos + 1
		ret.add pos
		loop
			pos = first_index_in_from(b, pos)
			if pos == -1 then return ret
			ret.add pos
			pos += length
		end
	end

	# Splits the content on self when encountering `b`
	#
	#     var a = "String is string".to_bytes.split_with('s'.ascii)
	#     assert a.length == 3
	#     assert a[0].hexdigest == "537472696E672069"
	#     assert a[1].hexdigest == "20"
	#     assert a[2].hexdigest == "7472696E67"
	fun split_with(b: BytePattern): Array[Bytes] do
		var fst = b.search_all_in(self)
		if fst.is_empty then return [clone]
		var retarr = new Array[Bytes]
		var prev = 0
		for i in fst do
			retarr.add(slice(prev, i - prev))
			prev = i + b.pattern_length
		end
		retarr.add slice_from(prev)
		return retarr
	end

	# Splits `self` in two parts at the first occurence of `b`
	#
	#     var a = "String is string".to_bytes.split_once_on('s'.ascii)
	#     assert a[0].hexdigest == "537472696E672069"
	#     assert a[1].hexdigest == "20737472696E67"
	fun split_once_on(b: BytePattern): Array[Bytes] do
		var spl = b.first_index_in(self)
		if spl == -1 then return [clone]
		var ret = new Array[Bytes].with_capacity(2)
		ret.add(slice(0, spl))
		ret.add(slice_from(spl + b.pattern_length))
		return ret
	end

	# Replaces all the occurences of `this` in `self` by `by`
	#
	#     var b = "String is string".to_bytes.replace(0x20u8, 0x41u8)
	#     assert b.hexdigest == "537472696E6741697341737472696E67"
	fun replace(pattern: BytePattern, bytes: BytePattern): Bytes do
		if is_empty then return new Bytes.empty
		var pos = pattern.search_all_in(self)
		if pos.is_empty then return clone
		var ret = new Bytes.with_capacity(length)
		var prev = 0
		for i in pos do
			ret.append_ns(items.fast_cstring(prev), i - prev)
			bytes.append_to ret
			prev = i + pattern.pattern_length
		end
		ret.append(slice_from(pos.last + pattern.pattern_length))
		return ret
	end

	# Decode `self` from percent (or URL) encoding to a clear string
	#
	# Replace invalid use of '%' with '?'.
	#
	#     assert "aBc09-._~".to_bytes.from_percent_encoding == "aBc09-._~".to_bytes
	#     assert "%25%28%29%3c%20%3e".to_bytes.from_percent_encoding == "%()< >".to_bytes
	#     assert ".com%2fpost%3fe%3dasdf%26f%3d123".to_bytes.from_percent_encoding == ".com/post?e=asdf&f=123".to_bytes
	#     assert "%25%28%29%3C%20%3E".to_bytes.from_percent_encoding == "%()< >".to_bytes
	#     assert "incomplete %".to_bytes.from_percent_encoding == "incomplete ?".to_bytes
	#     assert "invalid % usage".to_bytes.from_percent_encoding == "invalid ? usage".to_bytes
	#     assert "%c3%a9%e3%81%82%e3%81%84%e3%81%86".to_bytes.from_percent_encoding == "éあいう".to_bytes
	fun from_percent_encoding: Bytes do
		var tmp = new Bytes.with_capacity(length)
		var pos = 0
		while pos < length do
			var b = self[pos]
			if b != '%'.ascii then
				tmp.add b
				pos += 1
				continue
			end
			if length - pos < 2 then
				tmp.add '?'.ascii
				pos += 1
				continue
			end
			var bn = self[pos + 1]
			var bnn = self[pos + 2]
			if not bn.is_valid_hexdigit or not bnn.is_valid_hexdigit then
				tmp.add '?'.ascii
				pos += 1
				continue
			end
			tmp.add((bn.hexdigit_to_byteval << 4) + bnn.hexdigit_to_byteval)
			pos += 3
		end
		return tmp
	end

	# Is `b` a prefix of `self` ?
	fun has_prefix(b: BytePattern): Bool do return b.is_prefix(self)

	# Is `b` a suffix of `self` ?
	fun has_suffix(b: BytePattern): Bool do return b.is_suffix(self)

	redef fun is_suffix(b) do
		if length > b.length then return false
		var j = b.length - 1
		var i = length - 1
		while i > 0 do
			if self[i] != b[j] then return false
			i -= 1
			j -= 1
		end
		return true
	end

	redef fun is_prefix(b) do
		if length > b.length then return false
		for i in [0 .. length[ do if self[i] != b[i] then return false
		return true
	end
end

private class BytesIterator
	super IndexedIterator[Byte]

	var tgt: NativeString

	redef var index

	var max: Int

	init with_buffer(b: Bytes) do init(b.items, 0, b.length)

	redef fun is_ok do return index < max

	redef fun next do index += 1

	redef fun item do return tgt[index]
end

redef class Text
	# Returns a mutable copy of `self`'s bytes
	#
	# ~~~nit
	# assert "String".to_bytes isa Bytes
	# assert "String".to_bytes == [83u8, 116u8, 114u8, 105u8, 110u8, 103u8]
	# ~~~
	fun to_bytes: Bytes do
		var b = new Bytes.with_capacity(bytelen)
		append_to_bytes b
		return b
	end

	# Is `self` a valid hexdigest ?
	#
	#     assert "0B1d3F".is_valid_hexdigest
	#     assert not "5G".is_valid_hexdigest
	fun is_valid_hexdigest: Bool do
		for i in bytes do if not i.is_valid_hexdigit then return false
		return true
	end

	# Appends `self.bytes` to `b`
	fun append_to_bytes(b: Bytes) do
		for s in substrings do
			b.append_ns_from(s.items, s.bytelen, 0)
		end
	end

	# Returns a new `Bytes` instance with the digest as content
	#
	#     assert "0B1F4D".hexdigest_to_bytes == [0x0Bu8, 0x1Fu8, 0x4Du8]
	#
	# REQUIRE: `self` is a valid hexdigest and hexdigest.length % 2 == 0
	fun hexdigest_to_bytes: Bytes do
		var b = bytes
		var pos = 0
		var max = bytelen
		var ret = new Bytes.with_capacity(max / 2)
		while pos < max do
			ret.add((b[pos].hexdigit_to_byteval << 4) |
			b[pos + 1].hexdigit_to_byteval)
			pos += 2
		end
		return ret
	end

	# Gets the hexdigest of the bytes of `self`
	#
	#     assert "&lt;STRING&#47;&rt;".hexdigest == "266C743B535452494E47262334373B2672743B"
	fun hexdigest: String do
		var ln = bytelen
		var outns = new NativeString(ln * 2)
		var oi = 0
		for i in [0 .. ln[ do
			bytes[i].add_digest_at(outns, oi)
			oi += 2
		end
		return new FlatString.with_infos(outns, ln * 2)
	end

	# Return a `Bytes` instance where Nit escape sequences are transformed.
	#
	#     assert "B\\n\\x41\\u0103D3".unescape_to_bytes.hexdigest == "420A41F0908F93"
	fun unescape_to_bytes: Bytes do
		var res = new Bytes.with_capacity(self.bytelen)
		var was_slash = false
		var i = 0
		while i < length do
			var c = chars[i]
			if not was_slash then
				if c == '\\' then
					was_slash = true
				else
					res.add_char(c)
				end
				i += 1
				continue
			end
			was_slash = false
			if c == 'n' then
				res.add_char('\n')
			else if c == 'r' then
				res.add_char('\r')
			else if c == 't' then
				res.add_char('\t')
			else if c == '0' then
				res.add_char('\0')
			else if c == 'x' or c == 'X' then
				var hx = substring(i + 1, 2)
				if hx.is_hex then
					res.add(hx.to_hex.to_b)
				else
					res.add_char(c)
				end
				i += 2
			else if c == 'u' or c == 'U' then
				var hx = substring(i + 1, 6)
				if hx.is_hex then
					res.add_char(hx.to_hex.code_point)
				else
					res.add_char(c)
				end
				i += 6
			else
				res.add_char(c)
			end
			i += 1
		end
		return res
	end
end

redef class FlatText
	redef fun append_to_bytes(b) do
		b.append_ns_from(items, bytelen, 0)
	end
end

redef class NativeString
	# Creates a new `Bytes` object from `self` with `len` as length
	#
	# If `len` is null, strlen will determine the length of the Bytes
	fun to_bytes(len: nullable Int): Bytes do
		if len == null then len = cstring_length
		return new Bytes(self, len, len)
	end

	# Creates a new `Bytes` object from a copy of `self` with `len` as length
	#
	# If `len` is null, strlen will determine the length of the Bytes
	fun to_bytes_with_copy(len: nullable Int): Bytes do
		if len == null then len = cstring_length
		var nns = new NativeString(len)
		copy_to(nns, len, 0, 0)
		return new Bytes(nns, len, len)
	end
end

# Joins an array of bytes `arr` separated by `sep`
#
#     assert join_bytes(["String".to_bytes, "is".to_bytes, "string".to_bytes], ' '.ascii).hexdigest == "537472696E6720697320737472696E67"
fun join_bytes(arr: Array[Bytes], sep: nullable BytePattern): Bytes do
	if arr.is_empty then return new Bytes.empty
	sep = sep or else new Bytes.empty
	var endln = sep.pattern_length * (arr.length - 1)
	for i in arr do endln += i.length
	var ret = new Bytes.with_capacity(endln)
	ret.append(arr.first)
	for i in  [1 .. arr.length[ do
		sep.append_to(ret)
		ret.append arr[i]
	end
	return ret
end
