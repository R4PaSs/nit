
import standard
intrude import standard::ropes
intrude import standard::string

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

fun rope_buf_cct(str_size, nb_concats, count: Int)
do
	var s = "a" * str_size

	for i in [0..count] do
		var x: String = new RopeString
		for j in [0..nb_concats] do
			x += s
		end
	end
end

fun rope_cct(str_size, nb_concats, count: Int)
do
	var s = ("a" * str_size).as(FlatString)

	for i in [0..count] do
		var c: RopeNode = new StringLeaf(s)
		var str = new RopeString.from_root(c)
		var n: Concat
		for j in [0..nb_concats[ do
			var c2 = new StringLeaf(s)
			n = new Concat(c,c2)
			c = n
			str = new RopeString.from_root(n)
		end
	end
end

fun flats_cct(str_size, nb_concats, count: Int)
do
	var s = "a" * str_size

	for i in [0..count] do
		var x = ""
		for j in [0..nb_concats] do
			x += s
		end
	end
end

fun flatb_cct(str_size, nb_concats, count: Int)
do
	var s = "a" * str_size

	for i in [0..count] do
		var x = new FlatBuffer
		for j in [0..nb_concats] do
			x.append s
		end
		var s1 = x.to_s
	end
end

assert sys.args.length >= 4

if sys.args[0] == "rope" then
	rope_cct(sys.args[1].to_i, sys.args[2].to_i, sys.args[3].to_i)
else if sys.args[0] == "flats" then
	flats_cct(sys.args[1].to_i, sys.args[2].to_i, sys.args[3].to_i)
else if sys.args[0] == "buffered" then
	rope_buf_cct(sys.args[1].to_i, sys.args[2].to_i, sys.args[3].to_i)
else if sys.args[0] == "flatb" then
	flatb_cct(sys.args[1].to_i, sys.args[2].to_i, sys.args[3].to_i)
else
	print "Error: Unrecognized method of concat. Use either rope or flat."
	exit(1)
end

