# This file is part of NIT ( http://www.nitlanguage.org ).
#
# This file is free software, which comes along with NIT.  This software is
# distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
# without  even  the implied warranty of  MERCHANTABILITY or  FITNESS FOR A
# PARTICULAR PURPOSE.  You can modify it is you want,  provided this header
# is kept unaltered, and a notification of the changes is added.
# You  are  allowed  to  redistribute it and sell it, alone or is a part of
# another product.

# Basic integers of fixed-precision
#
# All classes defined here have C-equivalents and the semantics of their
# operations are the same as C's
#
# * Int8 => int8_t
# * Int16 => int16_t
# * UInt16 => uint16_t
# * Int32 => int32_t
# * UInt32 => uint32_t
#
# NOTE: No UInt8 is provided as Byte is the same
# SEE: kernel::Byte
#
# HOW TO USE:
# All classes can be instanciated via a literal rule.
# Namely, a suffix to append after the literal integer.
#
# * Int8 => i8
# * Byte => u8
# * Int16 => i16
# * UInt16 => u16
# * Int32 => i32
# * UInt32 => u32
module fixed_ints

import text

in "C" `{
#include <inttypes.h>
`}

redef class Numeric

	# The Int8 equivalent of `self`
	#
	#     assert (-1).to_i8 == 0xFFFFi8
	#     assert (1.9).to_i8 == 1i8
	fun to_i8: Int8 do return self.to_i.to_i8

	# The Int16 equivalent of `self`
	#
	#     assert (-1).to_i16 == 0xFFFFi16
	#     assert (1.9).to_i16 == 1i16
	fun to_i16: Int16 do return self.to_i.to_i16

	# The UInt16 equivalent of `self`
	#
	#     assert (-1).to_u16 == 0xFFFFu16
	#     assert (1.9).to_u16 == 1u16
	fun to_u16: UInt16 do return self.to_i.to_u16

	# The Int32 equivalent of `self`
	#
	#     assert (-1).to_i32 == 0xFFFFFFFFi32
	#     assert (1.9).to_i32 == 1i32
	fun to_i32: Int32 do return self.to_i.to_i32

	# The UInt32 equivalent of `self`
	#
	#     assert (-1).to_u32 == 0xFFFFFFFFu32
	#     assert (1.9).to_u32 == 1u32
	fun to_u32: UInt32 do return self.to_i.to_u32

end

redef class Float
	redef fun to_i8 is intern
	redef fun to_i16 is intern
	redef fun to_u16 is intern
	redef fun to_i32 is intern
	redef fun to_u32 is intern
end

redef class Byte
	redef fun to_i8 is intern
	redef fun to_i16 is intern
	redef fun to_u16 is intern
	redef fun to_i32 is intern
	redef fun to_u32 is intern
end

redef class Int
	redef fun to_i8 is intern
	redef fun to_i16 is intern
	redef fun to_u16 is intern
	redef fun to_i32 is intern
	redef fun to_u32 is intern
end

# Native 8-bit signed integer.
# Same as a C `int8_t`
universal Int8
	super Discrete
	super Numeric

	redef type OTHER: Int8

	redef fun successor(i) do return self + i.to_i8
	redef fun predecessor(i) do return self - i.to_i8

	redef fun object_id is intern
	redef fun hash do return self.to_i
	redef fun ==(i) is intern
	redef fun !=(i) is intern
	redef fun output is intern

	redef fun <=(i) is intern
	redef fun <(i) is intern
	redef fun >=(i) is intern
	redef fun >(i) is intern
	redef fun +(i) is intern

	#     assert -1i8 == 0xFFi8
	#     assert -0i8 == 0x00i8
	redef fun - is intern
	redef fun -(i) is intern
	redef fun *(i) is intern
	redef fun /(i) is intern

	# Modulo of `self` with `i`.
	#
	# Returns the remainder of division of `self` by `i`.
	#
	#     assert 5i8 % 2i8		== 1i8
	#     assert 10i8 % 2i8		== 0i8
	fun %(i: Int8): Int8 is intern

	redef fun zero do return 0.to_i8
	redef fun value_of(val) do return val.to_i8

	# `i` bits shift to the left
	#
	#     assert 5i8 << 1    == 10i8
	fun <<(i: Int): Int8 is intern

	# `i` bits shift to the right
	#
	#     assert 5i8 >> 1    == 2i8
	fun >>(i: Int): Int8 is intern

	redef fun to_i is intern
	redef fun to_f is intern
	redef fun to_b is intern
	redef fun to_i8 do return self
	redef fun to_i16 is intern
	redef fun to_u16 is intern
	redef fun to_i32 is intern
	redef fun to_u32 is intern

	redef fun distance(i) do return (self - i).to_i

	redef fun <=>(other)
	do
		if self < other then
			return -1
		else if other < self then
			return 1
		else
			return 0
		end
	end

	redef fun is_between(c, d)
	do
		if self < c or d < self then
			return false
		else
			return true
		end
	end

	redef fun max(other)
	do
		if self < other then
			return other
		else
			return self
		end
	end

	redef fun min(c)
	do
		if c < self then
			return c
		else
			return self
		end
	end

	# Returns the result of a binary AND operation on `self` and `i`
	#
	#     assert 0x10i8 & 0x01i8 == 0i8
	fun &(i: Int8): Int8 `{ return self & i; `}

	# Returns the result of a binary OR operation on `self` and `i`
	#
	#     assert 0x10i8 | 0x01i8 == 0x11i8
	fun |(i: Int8): Int8 `{ return self | i; `}

	# Returns the result of a binary XOR operation on `self` and `i`
	#
	#     assert 0x101i8 ^ 0x110i8 == 0x11i8
	fun ^(i: Int8): Int8 `{ return self ^ i; `}

	# Returns the 1's complement of `self`
	#
	#     assert ~0x2Fi8 == 0xD0i8
	fun ~: Int8 `{ return ~self; `}

	# C function to calculate the length of the `NativeString` to receive `self`
	private fun to_s_len: Int `{
		return snprintf(NULL, 0, "%"PRIi8, self);
	`}

	# C function to convert a nit Int to a NativeString (char*)
	private fun native_to_s(nstr: NativeString, strlen: Int) `{
		snprintf(nstr, strlen, "%"PRIi8, self);
	`}

	# Displayable Int8
	#
	#     assert 1i8.to_s       == "1"
	#     assert (-123i8).to_s  == "-123"
	redef fun to_s do
		var nslen = to_s_len
		var ns = new NativeString(nslen + 1)
		ns[nslen] = 0u8
		native_to_s(ns, nslen + 1)
		return ns.to_s_with_length(nslen)
	end
end

# Native 16-bit signed integer.
# Same as a C `int16_t`
universal Int16
	super Discrete
	super Numeric

	redef type OTHER: Int16

	redef fun successor(i) do return self + i.to_i16
	redef fun predecessor(i) do return self - i.to_i16

	redef fun object_id is intern
	redef fun hash do return self.to_i
	redef fun ==(i) is intern
	redef fun !=(i) is intern
	redef fun output is intern

	redef fun <=(i) is intern
	redef fun <(i) is intern
	redef fun >=(i) is intern
	redef fun >(i) is intern
	redef fun +(i) is intern

	#     assert -1i16 == 0xFFFFi16
	#     assert -0i16 == 0i16
	redef fun - is intern
	redef fun -(i) is intern
	redef fun *(i) is intern
	redef fun /(i) is intern

	# Modulo of `self` with `i`.
	#
	# Returns the remainder of division of `self` by `i`.
	#
	#     assert 5i16 % 2i16	== 1i16
	#     assert 10i16 % 2i16	== 0i16
	fun %(i: Int16): Int16 is intern

	redef fun zero do return 0.to_i16
	redef fun value_of(val) do return val.to_i16

	# `i` bits shift to the left
	#
	#     assert 5i16 << 1 == 10i16
	fun <<(i: Int): Int16 is intern

	# `i` bits shift to the right
	#
	#     assert 5i16 >> 1 == 2i16
	fun >>(i: Int): Int16 is intern

	redef fun to_i is intern
	redef fun to_f is intern
	redef fun to_b is intern
	redef fun to_i8 is intern
	redef fun to_i16 do return self
	redef fun to_u16 is intern
	redef fun to_i32 is intern
	redef fun to_u32 is intern

	redef fun distance(i) do return (self - i).to_i

	redef fun <=>(other)
	do
		if self < other then
			return -1
		else if other < self then
			return 1
		else
			return 0
		end
	end

	redef fun is_between(c, d)
	do
		if self < c or d < self then
			return false
		else
			return true
		end
	end

	redef fun max(other)
	do
		if self < other then
			return other
		else
			return self
		end
	end

	redef fun min(c)
	do
		if c < self then
			return c
		else
			return self
		end
	end

	# Returns the result of a binary AND operation on `self` and `i`
	#
	#     assert 0x10i16 & 0x01i16 == 0i16
	fun &(i: Int16): Int16 `{ return self & i; `}

	# Returns the result of a binary OR operation on `self` and `i`
	#
	#     assert 0x10i16 | 0x01i16 == 0x11i16
	fun |(i: Int16): Int16 `{ return self | i; `}

	# Returns the result of a binary XOR operation on `self` and `i`
	#
	#     assert 0x101i16 ^ 0x110i16 == 0x11i16
	fun ^(i: Int16): Int16 `{ return self ^ i; `}

	# Returns the 1's complement of `self`
	#
	#     assert ~0x2Fi16 == 0xFFD0i16
	fun ~: Int16 `{ return ~self; `}

	# C function to calculate the length of the `NativeString` to receive `self`
	private fun to_s_len: Int `{
		return snprintf(NULL, 0, "%"PRIi16, self);
	`}

	# C function to convert a nit Int to a NativeString (char*)
	private fun native_to_s(nstr: NativeString, strlen: Int) `{
		snprintf(nstr, strlen, "%"PRIi16, self);
	`}

	# Displayable Int16
	#
	#     assert 1i16.to_s       == "1"
	#     assert (-123i16).to_s  == "-123"
	redef fun to_s do
		var nslen = to_s_len
		var ns = new NativeString(nslen + 1)
		ns[nslen] = 0u8
		native_to_s(ns, nslen + 1)
		return ns.to_s_with_length(nslen)
	end
end

# Native 16-bit unsigned integer.
# Same as a C `uint16_t`
universal UInt16
	super Discrete
	super Numeric

	redef type OTHER: UInt16

	redef fun successor(i) do return self + i.to_u16
	redef fun predecessor(i) do return self - i.to_u16

	redef fun object_id is intern
	redef fun hash do return self.to_i
	redef fun ==(i) is intern
	redef fun !=(i) is intern
	redef fun output is intern

	redef fun <=(i) is intern
	redef fun <(i) is intern
	redef fun >=(i) is intern
	redef fun >(i) is intern
	redef fun +(i) is intern

	#     assert -1u16 == 0xFFFFu16
	#     assert -0u16 == 0u16
	redef fun - is intern
	redef fun -(i) is intern
	redef fun *(i) is intern
	redef fun /(i) is intern

	# Modulo of `self` with `i`.
	#
	# Returns the remainder of division of `self` by `i`.
	#
	#     assert 5u16 % 2u16	== 1u16
	#     assert 10u16 % 2u16	== 0u16
	fun %(i: UInt16): UInt16 is intern

	redef fun zero do return 0.to_u16
	redef fun value_of(val) do return val.to_u16

	# `i` bits shift to the left
	#
	#     assert 5u16 << 1    == 10u16
	fun <<(i: Int): UInt16 is intern

	# `i` bits shift to the right
	#
	#     assert 5u16 >> 1    == 2u16
	fun >>(i: Int): UInt16 is intern

	redef fun to_i is intern
	redef fun to_f is intern
	redef fun to_b is intern
	redef fun to_i8 is intern
	redef fun to_i16 is intern
	redef fun to_u16 do return self
	redef fun to_i32 is intern
	redef fun to_u32 is intern

	redef fun distance(i) do return (self - i).to_i

	redef fun <=>(other)
	do
		if self < other then
			return -1
		else if other < self then
			return 1
		else
			return 0
		end
	end

	redef fun is_between(c, d)
	do
		if self < c or d < self then
			return false
		else
			return true
		end
	end

	redef fun max(other)
	do
		if self < other then
			return other
		else
			return self
		end
	end

	redef fun min(c)
	do
		if c < self then
			return c
		else
			return self
		end
	end

	# Returns the result of a binary AND operation on `self` and `i`
	#
	#     assert 0x10u16 & 0x01u16 == 0u16
	fun &(i: UInt16): UInt16 `{ return self & i; `}

	# Returns the result of a binary OR operation on `self` and `i`
	#
	#     assert 0x10u16 | 0x01u16 == 0x11u16
	fun |(i: UInt16): UInt16 `{ return self | i; `}

	# Returns the result of a binary XOR operation on `self` and `i`
	#
	#     assert 0x101u16 ^ 0x110u16 == 0x11u16
	fun ^(i: UInt16): UInt16 `{ return self ^ i; `}

	# Returns the 1's complement of `self`
	#
	#     assert ~0x2Fu16 == 0xFFD0u16
	fun ~: UInt16 `{ return ~self; `}

	# C function to calculate the length of the `NativeString` to receive `self`
	private fun to_s_len: Int `{
		return snprintf(NULL, 0, "%"PRIu16, self);
	`}

	# C function to convert a nit Int to a NativeString (char*)
	private fun native_to_s(nstr: NativeString, strlen: Int) `{
		snprintf(nstr, strlen, "%"PRIu16, self);
	`}

	# Displayable UInt16
	#
	#     assert 1u16.to_s       == "1"
	#     assert (-123u16).to_s  == "65413"
	redef fun to_s do
		var nslen = to_s_len
		var ns = new NativeString(nslen + 1)
		ns[nslen] = 0u8
		native_to_s(ns, nslen + 1)
		return ns.to_s_with_length(nslen)
	end
end


# Native 32-bit signed integer.
# Same as a C `int32_t`
universal Int32
	super Discrete
	super Numeric

	redef type OTHER: Int32

	redef fun successor(i) do return self + i.to_i32
	redef fun predecessor(i) do return self - i.to_i32

	redef fun object_id is intern
	redef fun hash do return self.to_i
	redef fun ==(i) is intern
	redef fun !=(i) is intern
	redef fun output is intern

	redef fun <=(i) is intern
	redef fun <(i) is intern
	redef fun >=(i) is intern
	redef fun >(i) is intern
	redef fun +(i) is intern

	#     assert -1i32 == 0xFFFFFFFFi32
	#     assert -0i32 == 0x00i32
	redef fun - is intern
	redef fun -(i) is intern
	redef fun *(i) is intern
	redef fun /(i) is intern

	# Modulo of `self` with `i`.
	#
	# Returns the remainder of division of `self` by `i`.
	#
	#     assert 5i32 % 2i32		== 1i32
	#     assert 10i32 % 2i32		== 0i32
	fun %(i: Int32): Int32 is intern

	redef fun zero do return 0.to_i32
	redef fun value_of(val) do return val.to_i32

	# `i` bits shift to the left
	#
	#     assert 5i32 << 1    == 10i32
	fun <<(i: Int): Int32 is intern

	# `i` bits shift to the right
	#
	#     assert 5i32 >> 1    == 2i32
	fun >>(i: Int): Int32 is intern

	redef fun to_i is intern
	redef fun to_f is intern
	redef fun to_b is intern
	redef fun to_i8 is intern
	redef fun to_i16 is intern
	redef fun to_u16 is intern
	redef fun to_i32 do return self
	redef fun to_u32 is intern

	redef fun distance(i) do return (self - i).to_i

	redef fun <=>(other)
	do
		if self < other then
			return -1
		else if other < self then
			return 1
		else
			return 0
		end
	end

	redef fun is_between(c, d)
	do
		if self < c or d < self then
			return false
		else
			return true
		end
	end

	redef fun max(other)
	do
		if self < other then
			return other
		else
			return self
		end
	end

	redef fun min(c)
	do
		if c < self then
			return c
		else
			return self
		end
	end

	# Returns the result of a binary AND operation on `self` and `i`
	#
	#     assert 0x10i32 & 0x01i32 == 0i32
	fun &(i: Int32): Int32 `{ return self & i; `}

	# Returns the result of a binary OR operation on `self` and `i`
	#
	#     assert 0x10i32 | 0x01i32 == 0x11i32
	fun |(i: Int32): Int32 `{ return self | i; `}

	# Returns the result of a binary XOR operation on `self` and `i`
	#
	#     assert 0x101i32 ^ 0x110i32 == 0x11i32
	fun ^(i: Int32): Int32 `{ return self ^ i; `}

	# Returns the 1's complement of `self`
	#
	#     assert ~0x2Fi32 == 0xFFFFFFD0i32
	fun ~: Int32 `{ return ~self; `}

	# C function to calculate the length of the `NativeString` to receive `self`
	private fun to_s_len: Int `{
		return snprintf(NULL, 0, "%"PRIi32, self);
	`}

	# C function to convert a nit Int to a NativeString (char*)
	private fun native_to_s(nstr: NativeString, strlen: Int) `{
		snprintf(nstr, strlen, "%"PRIi32, self);
	`}

	# Displayable Int32
	#
	#     assert 1i32.to_s       == "1"
	#     assert (-123i32).to_s  == "-123"
	redef fun to_s do
		var nslen = to_s_len
		var ns = new NativeString(nslen + 1)
		ns[nslen] = 0u8
		native_to_s(ns, nslen + 1)
		return ns.to_s_with_length(nslen)
	end
end

# Native 32-bit unsigned integer.
# Same as a C `uint32_t`
universal UInt32
	super Discrete
	super Numeric

	redef type OTHER: UInt32

	redef fun successor(i) do return self + i.to_u32
	redef fun predecessor(i) do return self - i.to_u32

	redef fun object_id is intern
	redef fun hash do return self.to_i
	redef fun ==(i) is intern
	redef fun !=(i) is intern
	redef fun output is intern

	redef fun <=(i) is intern
	redef fun <(i) is intern
	redef fun >=(i) is intern
	redef fun >(i) is intern
	redef fun +(i) is intern

	#     assert -1u32 == 0xFFFFFFFFu32
	#     assert -0u32 == 0x00u32
	redef fun - is intern
	redef fun -(i) is intern
	redef fun *(i) is intern
	redef fun /(i) is intern

	# Modulo of `self` with `i`.
	#
	# Returns the remainder of division of `self` by `i`.
	#
	#     assert 5u32 % 2u32		== 1u32
	#     assert 10u32 % 2u32		== 0u32
	fun %(i: UInt32): UInt32 is intern

	redef fun zero do return 0.to_u32
	redef fun value_of(val) do return val.to_u32

	# `i` bits shift to the left
	#
	#     assert 5u32 << 1    == 10u32
	fun <<(i: Int): UInt32 is intern

	# `i` bits shift to the right
	#
	#     assert 5u32 >> 1    == 2u32
	fun >>(i: Int): UInt32 is intern

	redef fun to_i is intern
	redef fun to_f is intern
	redef fun to_b is intern
	redef fun to_i8 is intern
	redef fun to_i16 is intern
	redef fun to_u16 is intern
	redef fun to_i32 is intern
	redef fun to_u32 do return self

	redef fun distance(i) do return (self - i).to_i

	redef fun <=>(other)
	do
		if self < other then
			return -1
		else if other < self then
			return 1
		else
			return 0
		end
	end

	redef fun is_between(c, d)
	do
		if self < c or d < self then
			return false
		else
			return true
		end
	end

	redef fun max(other)
	do
		if self < other then
			return other
		else
			return self
		end
	end

	redef fun min(c)
	do
		if c < self then
			return c
		else
			return self
		end
	end

	# Returns the result of a binary AND operation on `self` and `i`
	#
	#     assert 0x10u32 & 0x01u32 == 0u32
	fun &(i: UInt32): UInt32 `{ return self & i; `}

	# Returns the result of a binary OR operation on `self` and `i`
	#
	#     assert 0x10u32 | 0x01u32 == 0x11u32
	fun |(i: UInt32): UInt32 `{ return self | i; `}

	# Returns the result of a binary XOR operation on `self` and `i`
	#
	#     assert 0x101u32 ^ 0x110u32 == 0x11u32
	fun ^(i: UInt32): UInt32 `{ return self ^ i; `}

	# Returns the 1's complement of `self`
	#
	#     assert ~0x2Fu32 == 0xFFFFFFD0u32
	fun ~: UInt32 `{ return ~self; `}

	# C function to calculate the length of the `NativeString` to receive `self`
	private fun to_s_len: Int `{
		return snprintf(NULL, 0, "%"PRIu32, self);
	`}

	# C function to convert a nit Int to a NativeString (char*)
	private fun native_to_s(nstr: NativeString, strlen: Int) `{
		snprintf(nstr, strlen, "%"PRIu32, self);
	`}

	# Displayable UInt32
	#
	#     assert 1u32.to_s       == "1"
	#     assert (-123u32).to_s  == "4294967173"
	redef fun to_s do
		var nslen = to_s_len
		var ns = new NativeString(nslen + 1)
		ns[nslen] = 0u8
		native_to_s(ns, nslen + 1)
		return ns.to_s_with_length(nslen)
	end
end
