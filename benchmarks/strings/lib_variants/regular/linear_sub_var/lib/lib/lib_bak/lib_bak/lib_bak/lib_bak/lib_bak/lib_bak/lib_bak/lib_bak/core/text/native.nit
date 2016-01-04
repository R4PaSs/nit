# This file is part of NIT ( http://www.nitlanguage.org ).
#
# This file is free software, which comes along with NIT.  This software is
# distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
# without  even  the implied warranty of  MERCHANTABILITY or  FITNESS FOR A
# PARTICULAR PURPOSE.  You can modify it is you want,  provided this header
# is kept unaltered, and a notification of the changes is added.
# You  are  allowed  to  redistribute it and sell it, alone or is a part of
# another product.

# Native structures for text and bytes
module native

import kernel
import math

in "C" `{
#ifndef NIT_STRING
	#define NIT_STRING
	// A char* wrapper with some facilities to improve runtime
	typedef struct nit_string {
		// Position of the next available byte in items
		long next;
		// Capacity of items
		long capacity;
		// The content of the native string
		char items[];
	} nit_string;
#endif

#ifdef __linux__
	#include <endian.h>
#endif
#ifdef __APPLE__
	#include <libkern/OSByteOrder.h>
	#define be32toh(x) OSSwapBigToHostInt32(x)
#endif

#ifdef __pnacl__
	#define be16toh(val) (((val) >> 8) | ((val) << 8))
	#define be32toh(val) ((be16toh((val) << 16) | (be16toh((val) >> 16))))
#endif
#ifndef be32toh
	#define be32toh(val) betoh32(val)
#endif
`}

redef class Byte
	# Gives the length of the UTF-8 char starting with `self`
	fun u8len: Int do
		if self & 0b1000_0000u8 == 0u8 then
			return 1
		else if self & 0b1110_0000u8 == 0b1100_0000u8 then
			return 2
		else if self & 0b1111_0000u8 == 0b1110_0000u8 then
			return 3
		else if self & 0b1111_1000u8 == 0b1111_0000u8 then
			return 4
		else
			return 1
		end
	end
end

redef class Int
	# Returns the code_point from a utf16 surrogate pair
	#
	#     assert 0xD83DDE02.from_utf16_surr == 0x1F602
	fun from_utf16_surr: Int do
		var hi = (self & 0xFFFF0000) >> 16
		var lo = self & 0xFFFF
		var cp = 0
		cp += (hi - 0xD800) << 10
		cp += lo - 0xDC00
		cp += 0x10000
		return cp
	end
end

# Native strings are simple C char *
extern class NativeString `{ char* `}
	# Creates a new NativeString with a capacity of `length`
	new(length: Int) is intern

	# Returns a char* starting at `index`.
	#
	# WARNING: Unsafe for extern code, use only for temporary
	# pointer manipulation purposes (e.g. write to file or such)
	fun fast_cstring(index: Int): NativeString is intern

	# Get char at `index`.
	fun [](index: Int): Byte is intern

	# Set char `item` at index.
	fun []=(index: Int, item: Byte) is intern

	# Copy `self` to `dest`.
	fun copy_to(dest: NativeString, length: Int, from: Int, to: Int) is intern

	redef fun ==(o) is intern do return is_same_instance(o)

	redef fun !=(o) is intern do return not is_same_instance(o)

	# Position of the first nul character.
	fun cstring_length: Int
	do
		var l = 0
		while self[l] != 0u8 do l += 1
		return l
	end

	# Parse `self` as an Int.
	fun atoi: Int is intern

	# Parse `self` as a Float.
	fun atof: Float `{ return atof(self); `}

	# Gets the UTF-8 char at index `pos`
	#
	# Index is expressed in Unicode chars
	#
	# ~~~raw
	#     assert "かきく".as(FlatString).items.char_at(0) == 'か'
	# ~~~
	#
	# If the char at position pos is an invalid Unicode char,
	# the Unicode replacement character � (0xFFFD) will be used.
	#
	# ~~~raw
	#     assert "かきく".as(FlatString).items.char_at(1) == '�'
	# ~~~
	fun char_at(pos: Int): Char do
		var c = self[pos]
		if c & 0x80u8 == 0u8 then return c.ascii
		var b = fetch_4_hchars(pos)
		var ret = 0
		if b & 0xC00000 != 0x800000 then return 0xFFFD.code_point
		if b & 0xE0000000 == 0xC0000000 then
			ret |= (b & 0x1F000000) >> 18
			ret |= (b & 0x3F0000) >> 16
			return ret.code_point
		end
		if not b & 0xC000 == 0x8000 then return 0xFFFD.code_point
		if b & 0xF0000000 == 0xE0000000 then
			ret |= (b & 0xF000000) >> 12
			ret |= (b & 0x3F0000) >> 10
			ret |= (b & 0x3F00) >> 8
			return ret.code_point
		end
		if not b & 0xC0 == 0x80 then return 0xFFFD.code_point
		if b & 0xF8000000 == 0xF0000000 then
			ret |= (b.to_i & 0x7000000) >> 6
			ret |= (b.to_i & 0x3F0000) >> 4
			ret |= (b.to_i & 0x3F00) >> 2
			ret |= b.to_i & 0x3F
			return ret.code_point
		end
		return 0xFFFD.code_point
	end

	# Gets the byte index of char at position `n` in UTF-8 String
	fun char_to_byte_index(n: Int): Int do return char_to_byte_index_cached(n, 0, 0)

	# Gets the length of the character at position `pos` (1 if invalid sequence)
	fun length_of_char_at(pos: Int): Int do
		var c = self[pos]
		if c & 0x80u8 == 0x00u8 then
			return 1
		else if c & 0xE0u8 == 0xC0u8 and self[pos + 1] & 0xC0u8 == 0x80u8 then
			return 2
		else if c & 0xF0u8 == 0xE0u8 and self[pos + 1] & 0xC0u8 == 0x80u8 and self[pos + 2] & 0xC0u8 == 0x80u8 then
			return 3
		else if c & 0xF8u8 == 0xF0u8 and self[pos + 1] & 0xC0u8 == 0x80u8 and self[pos + 2] & 0xC0u8 == 0x80u8 and self[pos + 3] & 0xC0u8 == 0x80u8 then
			return 4
		else
			return 1
		end
	end

	# Gets the byte index of char at position `n` in UTF-8 String
	#
	# `char_from` and `byte_from` are cached values to seek from.
	#
	# NOTE: char_from and byte_from are not guaranteed to be valid cache values
	# It it up to the client to ensure the validity of the information
	fun char_to_byte_index_cached(n, char_from, byte_from: Int): Int do
		var ns_i = byte_from
		var my_i = char_from

		var dist = n - my_i

		while dist > 0 do
			while dist >= 4 do
				var i = fetch_4_chars(ns_i)
				if i & 0x80808080 != 0 then break
				ns_i += 4
				my_i += 4
				dist -= 4
			end
			if dist == 0 then break
			ns_i += length_of_char_at(ns_i)
			my_i += 1
			dist -= 1
		end

		while dist < 0 do
			while dist <= -4 do
				var i = fetch_4_chars(ns_i - 4)
				if i & 0x80808080 != 0 then break
				ns_i -= 4
				my_i -= 4
				dist += 4
			end
			if dist == 0 then break
			ns_i = find_beginning_of_char_at(ns_i - 1)
			my_i -= 1
			dist += 1
		end

		return ns_i
	end

	# Gets the char index of byte at position `n` in a UTF-8 String
	#
	# `char_from` and `byte_from` are cached values to seek from.
	#
	# NOTE: char_from and byte_from are not guaranteed to be valid cache values
	# It it up to the client to ensure the validity of the information
	fun byte_to_char_index_cached(n, char_from, byte_from: Int): Int do
		var ns_i = byte_from
		var my_i = char_from

		while ns_i < n do
			ns_i += length_of_char_at(ns_i)
			my_i += 1
		end

		while ns_i > n do
			ns_i = find_beginning_of_char_at(ns_i - 1)
			my_i -= 1
		end

		return my_i
	end

	# Returns the beginning position of the char at position `pos`
	#
	# If the char is invalid UTF-8, `pos` is returned as-is
	#
	# ~~~raw
	# 	assert "abc".items.find_beginning_of_char_at(2) == 2
	# 	assert "か".items.find_beginning_of_char_at(1) == 0
	#	assert [0x41u8, 233u8].to_s.items.find_beginning_of_char_at(1) == 1
	# ~~~
	fun find_beginning_of_char_at(pos: Int): Int do
		var endpos = pos
		var c = self[pos]
		if c & 0x80u8 == 0x00u8 then return pos
		while c & 0xC0u8 == 0x80u8 do
			pos -= 1
			c = self[pos]
		end
		var stpos = pos
		if length_of_char_at(stpos) >= (endpos - stpos + 1) then return pos
		return endpos
	end

	# Number of UTF-8 characters in `self` starting at `from`, for a length of `bytelen`
	fun utf8_length(from, bytelen: Int): Int is intern do
		var st = from
		var ln = 0
		while bytelen > 0 do
			while bytelen >= 4 do
				var i = fetch_4_chars(st)
				if i & 0x80808080 != 0 then break
				bytelen -= 4
				st += 4
				ln += 4
			end
			if bytelen == 0 then break
			var cln = length_of_char_at(st)
			st += cln
			ln += 1
			bytelen -= cln
		end
		return ln
	end

	# Fetch 4 chars in `self` at `pos`
	fun fetch_4_chars(pos: Int): Int is intern do return fetch_4_ffi(pos)

	# Fetch 4 chars in `self` at `pos`
	fun fetch_4_hchars(pos: Int): Int is intern do return fetch_4h_ffi(pos)

	# FIXME: To remove when bootstrap supports PR #1898
	private fun fetch_4_ffi(pos: Int): Int `{ return (long)*((uint32_t*)(self+pos)); `}
	private fun fetch_4h_ffi(pos: Int): Int `{ return (long)be32toh(*((uint32_t*)(self+pos))); `}
end

# A NativeString with several attributes which allows it to run like a `Buffer`
extern class BufferedNativeString `{ nit_string* `}
	# Creates a new BufferedNativeString instance with a capacity of `length`
	new(length: Int) is intern `{
		nit_string* nstr = (nit_string*) malloc(2 * sizeof(long) + length);
		nstr->capacity = length;
		nstr->next = 0;
		return nstr;
	`}

	# Position of the next available byte in `items`
	fun next: Int is intern `{ return self->next; `}

	# Sets the value of `next` to `n`
	fun next=(n: Int) is intern `{ self->next = n; `}

	# Capacity (in bytes) of `items`
	fun capacity: Int is intern `{ return self->capacity; `}

	# Sets the value of `capacity` to `c`
	fun capacity=(c: Int) is intern `{ self->capacity = c; `}

	# The content of the string
	fun items: NativeString is intern `{ return self->items; `}

	# Appends the `length` first bytes of `ns` to `self`
	fun append(ns: NativeString, length: Int) do
		ns.copy_to(items, length, 0, next)
		next += length
	end

	# Number of UTF-8 characters in `self` starting at `from`, for a length of `bytelen`
	fun utf8_length(from, bytelen: Int): Int do return items.utf8_length(from, bytelen)

	# Fetch 4 chars in `self` at `pos`
	fun fetch_4_chars(pos: Int): Int is intern do return items.fetch_4_ffi(pos)

	# Fetch 4 chars in `self` at `pos`
	fun fetch_4_hchars(pos: Int): Int is intern do return items.fetch_4h_ffi(pos)

	# Returns the beginning position of the char at position `pos`
	#
	# If the char is invalid UTF-8, `pos` is returned as-is
	#
	# ~~~raw
	# 	assert "abc".items.find_beginning_of_char_at(2) == 2
	# 	assert "か".items.find_beginning_of_char_at(1) == 0
	#	assert [0x41u8, 233u8].to_s.items.find_beginning_of_char_at(1) == 1
	# ~~~
	fun find_beginning_of_char_at(pos: Int): Int do return items.find_beginning_of_char_at(pos)

	# Returns a char* starting at `index`.
	#
	# WARNING: Unsafe for extern code, use only for temporary
	# pointer manipulation purposes (e.g. write to file or such)
	fun fast_cstring(index: Int): NativeString is intern do return items.fast_cstring(index)

	# Get char at `index`.
	fun [](index: Int): Byte is intern do return items[index]

	# Set char `item` at index.
	fun []=(index: Int, item: Byte) is intern do items[index] = item

	# Copy `self` to `dest`.
	fun copy_to(dest: NativeString, length: Int, from: Int, to: Int) is intern do items.copy_to(dest, length, from, to)

	# Position of the first nul character.
	fun cstring_length: Int do return items.cstring_length

	# Parse `self` as an Int.
	fun atoi: Int is intern do return items.atoi

	# Parse `self` as a Float.
	fun atof: Float `{ return atof(self->items); `}

	# Gets the UTF-8 char at index `pos`
	#
	# Index is expressed in Unicode chars
	#
	# ~~~raw
	#     assert "かきく".as(FlatString).items.char_at(0) == 'か'
	# ~~~
	#
	# If the char at position pos is an invalid Unicode char,
	# the Unicode replacement character � (0xFFFD) will be used.
	#
	# ~~~raw
	#     assert "かきく".as(FlatString).items.char_at(1) == '�'
	# ~~~
	fun char_at(pos: Int): Char do return items.char_at(pos)

	# Gets the byte index of char at position `n` in UTF-8 String
	fun char_to_byte_index(n: Int): Int do return items.char_to_byte_index_cached(n, 0, 0)

	# Gets the length of the character at position `pos` (1 if invalid sequence)
	fun length_of_char_at(pos: Int): Int do return items.length_of_char_at(pos)

	# Gets the byte index of char at position `n` in UTF-8 String
	#
	# `char_from` and `byte_from` are cached values to seek from.
	#
	# NOTE: char_from and byte_from are not guaranteed to be valid cache values
	# It it up to the client to ensure the validity of the information
	fun char_to_byte_index_cached(n, char_from, byte_from: Int): Int do return items.char_to_byte_index_cached(n, char_from, byte_from)

	# Gets the char index of byte at position `n` in a UTF-8 String
	#
	# `char_from` and `byte_from` are cached values to seek from.
	#
	# NOTE: char_from and byte_from are not guaranteed to be valid cache values
	# It it up to the client to ensure the validity of the information
	fun byte_to_char_index_cached(n, char_from, byte_from: Int): Int do return items.byte_to_char_index_cached(n, char_from, byte_from)
end
