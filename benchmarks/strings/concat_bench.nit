# Bench to determine after which size a Rope becomes relevant to build instead of a FlatString.
module concat_bench

intrude import standard::ropes
intrude import standard::string
import standard

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

fun flatstring_cct_bench(str_size: Int, count: Int)
do
	var lft = "a" * str_size
	var rgt = "a" * str_size

	assert lft isa FlatString
	assert rgt isa FlatString

	for i in [0..count] do
		var str = lft + rgt
	end
end

fun rope_cct_bench(str_size: Int, count: Int)
do
	var lft = "a" * str_size
	var rgt = "a" * str_size

	assert lft isa FlatString
	assert rgt isa FlatString

	for i in [0..count] do
		var cct = new Concat
		var l = new Leaf(lft)
		var r = new Leaf(rgt)
		cct.right = r
		cct.left = l
		var str = new RopeString.from_root(cct)
	end
end

assert sys.args.length == 3

if sys.args[0] == "rope" then
	rope_cct_bench(sys.args[1].to_i, sys.args[2].to_i)
else if sys.args[0] == "flat" then
	flatstring_cct_bench(sys.args[1].to_i, sys.args[2].to_i)
else
	print "Error: Unrecognized method of concat. Use either rope or flat."
	abort
end

