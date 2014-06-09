# This file is part of NIT ( http://www.nitlanguage.org ).
#
# This file is free software, which comes along with NIT.  This software is
# distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
# without  even  the implied warranty of  MERCHANTABILITY or  FITNESS FOR A
# PARTICULAR PURPOSE.  You can modify it if you want,  provided this header
# is kept unaltered, and a notification of the changes is added.
# You  are  allowed  to  redistribute it and sell it, alone or as a part of
# another product.

# Use Ropes instead of Flats for every operation on a String when this module is imported
#
# May (read will) induce a significant slowdown when imported.
#
module ropes_everywhere

intrude import ::standard::string
import ::standard

redef class Array[E]

	redef fun to_s
	do
		var s: String = new RopeString
		var i = 0
		var l = length
		while i < l do
			var e = self[i]
			if e != null then s += e.to_s
			i += 1
		end
		return s
	end

end

redef class Collection[E]

	redef fun to_s
	do
		var s: String = new RopeString
		for e in self do if e != null then s += e.to_s
		return s
	end

	redef fun join(sep)
	do
		if is_empty then return ""

		var s: String = new RopeString # Result

 		# Concat first item
		var i = iterator
		var e = i.item
		if e != null then s += e.to_s

		# Concat other items
		i.next
		while i.is_ok do
			s += sep
			e = i.item
			if e != null then s += e.to_s
			i.next
		end
		return s
	end
end

redef class Map[K,V]
	redef fun join(sep: String, couple_sep: String): String
	do
		if is_empty then return ""

		var s: String = new RopeString # Result

		# Concat first item
		var i = iterator
		var k = i.key
		var e = i.item
		s += "{k}{couple_sep}{e or else "<null>"}"

		# Concat other items
		i.next
		while i.is_ok do
			s += sep
			k = i.key
			e = i.item
			s += "{k}{couple_sep}{e or else "<null>"}"
			i.next
		end
		return s
	end
end

redef class NativeString

	redef fun to_s_with_length(length: Int): String
	do
		assert length >= 0
		var s = new FlatString.with_infos(self, length, 0, length - 1)
		return new RopeString.from(s)
	end

	redef fun to_s_with_copy: String
	do
		var length = cstring_length
		var new_self = calloc_string(length + 1)
		copy_to(new_self, length, 0, 0)
		var s = new FlatString.with_infos(new_self, length, 0, length - 1)
		return new RopeString.from(s)
	end

end

