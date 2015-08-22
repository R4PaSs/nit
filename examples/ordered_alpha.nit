redef class Text

	fun is_alpha_ordered: Bool do
		for i in [0 .. length - 1[ do
			if chars[i] > chars[i + 1] then return false
		end
		return true
	end

	fun is_reverse_alpha_ordered: Bool do
		for i in [0 .. length - 1[ do
			if chars[i] < chars[i + 1] then return false
		end
		return true
	end
end

while not stdin.eof do
	var s = gets
	if s.is_alpha_ordered then
		print "{s} IN ORDER"
	else if s.is_reverse_alpha_ordered then
		print "{s} REVERSE ORDER"
	else
		print "{s} NOT IN ORDER"
	end
end
