# Pure nit implementation of arbitrary-precision integers
module bigints

import fixed_ints

class Bigint
	super Numeric

	redef type OTHER: Bigint

	# Size of limbs
	var size: Int = 0
	# Allocated size of `limbs`
	var alloc: Int = 0
	# For portability/performance purposes,
	# let's assume that limbs are 32-bit long bit fields
	var limbs: NativeArray[UInt32] is noinit

	init with_capacity(cap: Int) do
		alloc = cap
		limbs = new NativeArray[UInt32](cap)
	end

	init from_int(i: Int) do
		size = 1
		alloc = 1
		if i < 0 then
			i = -i
			size = -1
		end
		limbs = new NativeArray[UInt32](1)
		limbs[0] = i.to_u32
	end
end
