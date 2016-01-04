# This file is part of NIT ( http://www.nitlanguage.org ).
#
# This file is free software, which comes along with NIT.  This software is
# distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
# without  even  the implied warranty of  MERCHANTABILITY or  FITNESS FOR A
# PARTICULAR PURPOSE.  You can modify it is you want,  provided this header
# is kept unaltered, and a notification of the changes is added.
# You  are  allowed  to  redistribute it and sell it, alone or is a part of
# another product.

# All kinds of native types with C-style semantics that are implemented through FFI
module native_types

`{
#include <stdint.h>
`}

# A 16-bit signed integer
class Int16 `{int16_t`}
	super Numeric

	redef type OTHER: Int16

	new(val: Int) `{ return (int16_t)val; `}

	redef fun+(o) `{ return self + o; `}

	redef fun -(o) `{ return self - o; `}

	redef fun *(o) `{ return self * o; `}

	redef fun /(o) `{ return self / o; `}

	fun %(o: Int16): Int16 `{ return self % o; `}

	fun >>(o: Int): Int16 `{ return self >> o; `}

	fun <<(o: Int): Int16 `{ return self << o; `}
end

# A 16-bit unsigned integer
class UInt16 `{uint16_t`}
	super Numeric

	redef type OTHER: UInt16

	redef fun+(o) `{ return self + o; `}

	redef fun -(o) `{ return self - o; `}

	redef fun *(o) `{ return self * o; `}

	redef fun /(o) `{ return self / o; `}

	fun %(o: UInt16): UInt16 `{ return self % o; `}

	fun >>(o: Int): UInt16 `{ return self >> o; `}

	fun <<(o: Int): UInt16 `{ return self << o; `}
end

# A 32-bit signed integer
class Int32 `{int32_t`}
	super Numeric

	redef type OTHER: Int32

	redef fun+(o) `{ return self + o; `}

	redef fun -(o) `{ return self - o; `}

	redef fun *(o) `{ return self * o; `}

	redef fun /(o) `{ return self / o; `}

	fun %(o: Int32): Int16 `{ return self % o; `}

	fun >>(o: Int): Int32 `{ return self >> o; `}

	fun <<(o: Int): Int32 `{ return self << o; `}
end

# A 32-bit unsigned integer
class UInt32 `{uint32_t`}
	super Numeric

	redef type OTHER: UInt32

	redef fun+(o) `{ return self + o; `}

	redef fun -(o) `{ return self - o; `}

	redef fun *(o) `{ return self * o; `}

	redef fun /(o) `{ return self / o; `}

	fun %(o: UInt32): UInt32 `{ return self % o; `}

	fun >>(o: Int): UInt32 `{ return self >> o; `}

	fun <<(o: Int): UInt32 `{ return self << o; `}
end

# An 8-bit signed integer
class Int8 `{int8_t`}
	super Numeric

	redef type OTHER: Int8

	redef fun+(o) `{ return self + o; `}

	redef fun -(o) `{ return self - o; `}

	redef fun *(o) `{ return self * o; `}

	redef fun /(o) `{ return self / o; `}

	fun %(o: Int8): Int8 `{ return self % o; `}

	fun >>(o: Int): Int8 `{ return self >> o; `}

	fun <<(o: Int): Int8 `{ return self << o; `}
end
