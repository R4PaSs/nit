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

	fun cct_to_b(p: String): FlatBuffer
	do
		var o = p.as(FlatString)
		var finlen = length + o.length
		var ns = calloc_string(buf_len)
		items.copy_to(ns, length, index_from, 0)
		o.items.copy_to(ns, length, index_from, length)
		return new FlatBuffer.with_infos(length, buf_len, items)
	end

end

redef class FlatBuffer
	
	init with_infos(len: Int, cap: Int, items: NativeString)
	do
		length = len
		capacity = cap
		self.items = items
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
		var l = new StringLeaf(lft)
		var r = new StringLeaf(rgt)
		var str = new RopeString.from_root(new Concat(l,r))
	end
end

fun buffered_rope_cct_bench(str_size: Int, count: Int)
do
	var lft = "a" * str_size
	var rgt = "a" * str_size

	assert lft isa FlatString
	assert rgt isa FlatString

	for i in [0..count] do
		var b = new FlatBuffer.with_capacity(buf_len)
		b.append(lft)
		b.append(rgt)
		var str = new RopeString.from_root(new BufferLeaf(b))
	end
end

fun rope_flatcct_bench(str_size: Int, count: Int)
do
	var lft = "a" * str_size
	var rgt = "a" * str_size

	assert lft isa FlatString
	assert rgt isa FlatString

	for i in [0..count] do
		var f = lft + rgt
		var s = new RopeString.from_root(new StringLeaf(f.as(FlatString)))
	end
end

fun buff_rope_cct_opt_bench(str_size: Int, count: Int)
do
	var lft = "a" * str_size
	var rgt = "a" * str_size

	assert lft isa FlatString
	assert rgt isa FlatString

	for i in [0..count] do
		var s = new RopeString.from_root(new BufferLeaf(lft.cct_to_b(rgt)))
	end
end

assert sys.args.length >= 3

if sys.args[0] == "rope" then
	rope_cct_bench(sys.args[1].to_i, sys.args[2].to_i)
else if sys.args[0] == "flat" then
	flatstring_cct_bench(sys.args[1].to_i, sys.args[2].to_i)
else if sys.args[0] == "buffered" then
	buffered_rope_cct_bench(sys.args[1].to_i, sys.args[2].to_i)
else if sys.args[0] == "cct_buff" then
	buff_rope_cct_opt_bench(sys.args[1].to_i, sys.args[2].to_i)
else if sys.args[0] == "rope_flat" then
	rope_flatcct_bench(sys.args[1].to_i, sys.args[2].to_i)
else
	print "Error: Unrecognized method of concat. Use either rope or flat."
	exit(1)
end

