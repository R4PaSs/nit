# An alternative implementation of Strings with constant-time substring
module cst_substring

intrude import standard::string
intrude import standard::ropes

redef class FlatString

	# Index in _items of the start of the string
	var index_from: Int

	# Index in _items of the last item of the string
	var index_to: Int

	private init with_infos(items: NativeString, len, from, to: Int) do
		self.items = items
		length = len
		index_from = from
		index_to = to
	end

	redef fun [](index)
	do
		# Check that the index (+ index_from) is not larger than indexTo
		# In other terms, if the index is valid
		assert index >= 0
		assert (index + index_from) <= index_to
		return items[index + index_from]
	end

	redef fun substring(from, count)
	do
		assert count >= 0

		if from < 0 then
			count += from
			if count < 0 then count = 0
			from = 0
		end

		var real_from = index_from + from

		if (real_from + count) > index_to then count = index_to - real_from + 1

		if count <= 0 then return empty

		var to = real_from + count - 1

		return new FlatString.with_infos(items, count, real_from, to)
	end

	redef fun to_upper
	do
		var outstr = new NativeString(length + 1)
		var out_index = 0

		var myitems = items

		for i in [index_from .. index_to] do
			outstr[out_index] = myitems[i].to_upper
			out_index += 1
		end

		outstr[length] = '\0'

		return new FlatString.with_infos(outstr, length, 0, length - 1)
	end

	redef fun to_lower
	do
		var outstr = new NativeString(length + 1)
		var out_index = 0

		var myitems = items

		for i in [index_from .. index_to] do
			outstr[out_index] = myitems[i].to_lower
			out_index += 1
		end

		outstr[length] = '\0'

		return new FlatString.with_infos(outstr, length, 0, length - 1)
	end

	redef fun output do for i in [index_from .. index_to] do items[i].output

	redef fun to_cstring: NativeString
	do
		if real_items != null then
			return real_items.as(not null)
		else
			var new_items = new NativeString(length + 1)
			items.copy_to(new_items, length, index_from, 0)
			new_items[length] = '\0'
			real_items = new_items
			return new_items
		end
	end

	redef fun ==(other)
	do
		if object_id == other.object_id then return true

		if not other isa FlatString then return super

		if other.length != length then return false

		var itsitems = other.items
		var myitems = items

		var opos = other.index_from

		for i in [index_from .. index_to] do
			if myitems[i] != itsitems[opos] then return false
			opos += 1
		end

		return true
	end

	redef fun <(other)
	do
		if self.object_id == other.object_id then return false

		if not other isa FlatString then return super

		var my_curr_char : Char
		var its_curr_char : Char

		var my_items = self.items
		var its_items = other.items

		var my_length = self.length
		var its_length = other.length

		var max = if my_length < its_length then my_length else its_length

		var opos = other.index_from

		for i in [index_from .. max] do
			my_curr_char = my_items[i]
			its_curr_char = its_items[opos]

			if my_curr_char != its_curr_char then
				if my_curr_char < its_curr_char then return true
				return false
			end

			opos += 1
		end

		return my_length < its_length
	end

	redef fun +(o) do
		var s = o.to_s
		var slen = s.length
		var mlen = length
		if slen == 0 then return self
		if mlen == 0 then return s
		var nlen = slen + mlen
		if s isa FlatString then
			if nlen > maxlen then return new Concat(self, s)
			var mits = items
			var sits = s.items
			var sifrom = s.index_from
			var mifrom = index_from
			var ns = new NativeString(nlen + 1)
			mits.copy_to(ns, mlen, mifrom, 0)
			sits.copy_to(ns, slen, sifrom, mlen)
			return ns.to_s_with_length(nlen)
		else if s isa Concat then
			var sl = s.left
			var sllen = sl.length
			if sllen + mlen > maxlen then return new Concat(self, s)
			return new Concat(self + sl, s.right)
		else
			abort
		end
	end

	redef fun hash
	do
		if hash_cache == null then
			# djb2 hash algorithm
			var h = 5381

			var myitems = items

			for i in [index_from .. index_to] do
				h = h.lshift(5) + h + myitems[i].ascii
				i += 1
			end

			hash_cache = h
		end

		return hash_cache.as(not null)
	end
end

redef class FlatStringReverseIterator

	var target: FlatString

	redef init with_pos(tgt: FlatString, pos: Int)
	do
		target = tgt
		target_items = tgt.items
		curr_pos = pos + tgt.index_from
	end

	redef fun is_ok do return curr_pos >= target.index_from

	redef fun index do return curr_pos - target.index_from
end

redef class FlatStringIterator

	var target: FlatString

	redef init with_pos(tgt: FlatString, pos: Int)
	do
		target = tgt
		target_items = tgt.items
		curr_pos = pos + tgt.index_from
		max = tgt.index_to + 1
	end

	redef fun index do return curr_pos - target.index_from
end

redef class FlatStringCharView

	redef fun [](index)
	do
		# Check that the index (+ index_from) is not larger than indexTo
		# In other terms, if the index is valid
		assert index >= 0
		var target = self.target
		var r_index = index + target.index_from
		assert (r_index) <= target.index_to
		return target.items[r_index]
	end
end

redef class FlatBuffer

	redef fun times(repeats)
	do
		var x = new FlatString.with_infos(items, length, 0, length - 1)
		for i in [1..repeats[ do
			append(x)
		end
	end
end

redef class Array[E]

	# Fast implementation
	redef fun to_s
	do
		var l = length
		if l == 0 then return ""
		if l == 1 then if self[0] == null then return "" else return self[0].to_s
		var its = _items
		var na = new NativeArray[String](l)
		var i = 0
		var sl = 0
		var mypos = 0
		while i < l do
			var itsi = its[i]
			if itsi == null then
				i += 1
				continue
			end
			var tmp = itsi.to_s
			sl += tmp.length
			na[mypos] = tmp
			i += 1
			mypos += 1
		end
		var ns = new NativeString(sl + 1)
		ns[sl] = '\0'
		i = 0
		var off = 0
		while i < mypos do
			var tmp = na[i]
			var tpl = tmp.length
			if tmp isa FlatString then
				tmp.items.copy_to(ns, tpl, tmp.index_from, off)
				off += tpl
			else
				for j in tmp.substrings do
					var s = j.as(FlatString)
					var slen = s.length
					s.items.copy_to(ns, slen, s.index_from, off)
					off += slen
				end
			end
			i += 1
		end
		return ns.to_s_with_length(sl)
	end
end

redef class NativeString
	# Returns `self` as a String of `length`.
	redef fun to_s_with_length(length: Int): FlatString
	do
		assert length >= 0
		var str = new FlatString.with_infos(self, length, 0, length - 1)
		return str
	end

	# Returns `self` as a new String.
	redef fun to_s_with_copy: FlatString
	do
		var length = cstring_length
		var new_self = new NativeString(length + 1)
		copy_to(new_self, length, 0, 0)
		var str = new FlatString.with_infos(new_self, length, 0, length - 1)
		new_self[length] = '\0'
		str.real_items = new_self
		return str
	end
end

redef class Concat

	redef fun to_cstring do
		var len = length
		var ns = new NativeString(len + 1)
		ns[len] = '\0'
		var off = 0
		for i in substrings do
			var ilen = i.length
			i.as(FlatString).items.copy_to(ns, ilen, i.as(FlatString).index_from, off)
			off += ilen
		end
		return ns
	end

end

redef class RopeBuffer

	redef fun append(s) do
		var slen = s.length
		length += slen
		var rp = rpos
		if s isa Rope or slen > maxlen then
			if rp > 0 and dumped != rp then
				str += new FlatString.with_infos(ns, rp - dumped, dumped, rp - 1)
				dumped = rp
			end
			str = str + s
			return
		end
		var remsp = buf_size - rp
		var sits: NativeString
		var begin: Int
		if s isa FlatString then
			begin = s.index_from
			sits = s.items
		else if s isa FlatBuffer then
			begin = 0
			sits = s.items
		else
			if slen <= remsp then
				for i in s.chars do
					ns[rpos] = i
					rpos += 1
				end
			else
				var spos = 0
				for i in [0..remsp[ do
					ns[rpos] = s[spos]
					rpos += 1
					spos += 1
				end
				dump_buffer
				while spos < slen do
					ns[rpos] = s[spos]
					spos += 1
					rpos += 1
				end
			end
			return
		end
		if slen <= remsp then
			if remsp <= 0 then
				dump_buffer
				rpos = 0
			else
				sits.copy_to(ns, slen, begin, rp)
				rpos += slen
			end
		else
			sits.copy_to(ns, remsp, begin, rp)
			rpos = buf_size
			dump_buffer
			var nlen = slen - remsp
			sits.copy_to(ns, nlen, begin + remsp, 0)
			rpos = nlen
		end
	end

	# Converts the Buffer to a FlatString, appends it to
	# the final String and re-allocates a new larger Buffer.
	redef fun dump_buffer do
		written = false
		var nstr = new FlatString.with_infos(ns, rpos - dumped, dumped, rpos - 1)
		str += nstr
		var bs = buf_size
		bs = bs * 2
		ns = new NativeString(bs)
		buf_size = bs
		dumped = 0
	end

	redef fun to_s do
		written = true
		var nnslen = rpos - dumped
		if nnslen == 0 then return str
		return str + new FlatString.with_infos(ns, rpos - dumped, dumped, rpos - 1)
	end

	redef fun reverse do
		# Flush the buffer in order to only have to reverse `str`.
		if rpos > 0 and dumped != rpos then
			str += new FlatString.with_infos(ns, rpos - dumped, dumped, rpos - 1)
			dumped = rpos
		end
		str = str.reversed
	end
end

redef class RopeBufSubstringIterator
	redef init(str: RopeBuffer) is old_style_init do
		iter = str.str.substrings
		nsstr = new FlatString.with_infos(str.ns, str.rpos - str.dumped, str.dumped, str.rpos - 1)
		if str.length == 0 then nsstr_done = true
	end
end
