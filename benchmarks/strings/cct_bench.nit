module cct_bench

import standard
import splay_ropes
intrude import standard::string
intrude import standard::ropes

redef class FlatString

	# Ensures the behaviour is correct for this bench
	redef fun +(p)
	do
		var o = p.as(FlatString)
		var finlen = length + o.length
		var ns = calloc_string(finlen)
		items.copy_to(ns, length, index_from, 0)
		o.items.copy_to(ns, o.length, o.index_from, length)
		return ns.to_s_with_length(finlen)
	end

end

fun bench_cct_ropestring(size: Int, cnt: Int) do
	var st: String = new RopeString

	var cct_str = "a" * size

	for i in [0..cnt] do
		st += cct_str
	end
end

fun bench_cct_flatstring(size: Int, cnt: Int) do

	var st = ""

	var cct_str = "a" * size

	for i in [0..cnt] do
		st += cct_str
	end
end

fun bench_cct_flatbuffer(size: Int, cnt: Int) do

	var st = new FlatBuffer

	var cct_str = "a" * size

	for i in [0..cnt] do
		st.append(cct_str)
	end
	st.to_s
end

if args[0] == "rope" then
	bench_cct_ropestring(args[1].to_i, args[2].to_i)
else if args[0] == "flats" then
	bench_cct_flatstring(args[1].to_i, args[2].to_i)
else if args[0] == "flatb" then
	bench_cct_flatbuffer(args[1].to_i, args[2].to_i)
else
	print "Invalid mode, use rope, flats or flatb"
	exit(1)
end

