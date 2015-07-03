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

redef class Byte
	# Gives then length of the UTF-8 char starting with `self`
	private fun u8len: Int do
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
	#     assert "かきく".as(FlatString).items.char_at(0) == 'か'
	#     assert "かきく".as(FlatString).items.char_at(1) == '�'
	#
	# If the char at position pos is an invalid Unicode char,
	# the Unicode replacement character � (0xFFFD) will be used.
	fun char_at(pos: Int): Char `{
		char c = self[pos];
		if((c & 0x80) == 0x00) return (uint32_t)c;
		if((c & 0xE0) == 0xC0) return ((((uint32_t)c) & 0x1F) << 6) + ((((uint32_t)self[pos + 1] & 0x3F)));
		if((c & 0xF0) == 0xE0) return ((((uint32_t)c) & 0xF) << 12) + ((((uint32_t)self[pos + 1]) & 0x3F) << 6) + ((((uint32_t)self[pos + 2] & 0x3F)));
		if((c & 0xF7) == 0xF0) return ((((uint32_t)c) & 0x7) << 18) + ((((uint32_t)self[pos + 1]) & 0x3F) << 12) + ((((uint32_t)self[pos + 2]) & 0x3F) << 6) + ((((uint32_t)self[pos + 3] & 0x3F)));
		return 0xFFFD;
	`}

	# Is the byte at position `pos` a valid UTF-8 char start
	#
	#       assert "か".items.is_valid_utf8_char(0)
	#       assert not "か".items.is_valid_utf8_char(1)
	fun is_valid_utf8_char(pos: Int): Bool do
		var c = self[pos]
		if c & 0x80u8 != 0u8 and
		c & 0xE0u8 != 0xC0u8 and
		c & 0xF0u8 != 0xE0u8 and
		c & 0xF7u8 != 0xF0u8 then
			return false
		end
		return true
	end

	# Gets the byte index of char at position `n` in UTF-8 String
	fun char_to_byte_index(n: Int): Int do return char_to_byte_index_cached(n, 0, 0)

	# Gets the byte index of char at position `n` in UTF-8 String,
	# `char_from` and `byte_from` are cached values to seek from.
	#
	# NOTE: char_from and byte_from are not guaranteed to be valid cache values
	# It it up to the client to ensure the validity of the information
	fun char_to_byte_index_cached(n, char_from, byte_from: Int): Int do
		var ns_i = byte_from
		var my_i = char_from

		while my_i < n do
			var c = self[ns_i]

			if c & 0x80u8 == 0u8 then
				ns_i += 1
			else if c & 0xE0u8 == 0xC0u8 then
				ns_i += 2
			else if c & 0xF0u8 == 0xE0u8 then
				ns_i += 3
			else if c & 0xF7u8 == 0xF0u8 then
				ns_i += 4
			else
				ns_i += 1
			end

			my_i += 1
		end

		while my_i > n do
			ns_i -= 1
			var c = self[ns_i]
			if c & 0xC0u8 != 0x80u8 then
				my_i -= 1
			end
		end

		return ns_i
	end

	# Assuming `pos` might be in the middle of a char
	# this returns the beginning position of the char
	#
	# 	assert "abc".items.find_beginning_of_char_at(2) == 2
	# 	assert "か".items.find_beginning_of_char_at(1) == 0
	fun find_beginning_of_char_at(pos: Int): Int do
		var c = self[pos]
		while c & 0xC0u8 == 0x80u8 do
			pos -= 1
			c = self[pos]
		end
		return pos
	end

	# Gets the bytewise position of the `n`th character starting from `from`
	fun get_char_pos_from(n: Int, from: Int): Int do
		var c: Byte
		var st = 0
		while st < n do
			c = self[from]
			from += c.u8len
			st += 1
		end
		return from
	end
end
