# Introduces a self-balancing method on Rope, using a Splay Tree
module splay_ropes

intrude import ropes

redef class Rope

	# Performs a Left rotation on node `x`
	# Since a Rope does not have any notion of parent in its node, they need to be passed as arguments if available.
	private fun left_rotate(r: Concat): Concat
	do
		var rr = r.right.as(Concat)
		var rl = r.left
		var pl = rr.left
		var pr = rr.right
		var nr = new Concat(rl, pl)
		var np = new Concat(nr, pr)
		return np
	end

	# Performs a Right rotation on node `r`
	# Since a Rope does not have any notion of parent in its node, they need to be passed as arguments if available.
	private fun right_rotate(r: Concat): Concat
	do
		var rl = r.left.as(Concat)
		var rr = r.right
		var pr = rl.right
		var pl = rl.left
		var nr = new Concat(pr, rr)
		var np = new Concat(pl, nr)
		return np
	end

	# Performs a Splay operation on a complete path
	# The last node of the path will become the root.
	private fun splay(path: Path): nullable Concat
	do
		var st = path.stack
		if st.is_empty then return null
		var cct = st.pop.node
		while not st.is_empty do
			var tmp = st.pop
			var nod: Concat
			if tmp.left then
				nod = new Concat(cct, tmp.node.right)
				cct = right_rotate(nod)
			else
				nod = new Concat(tmp.node.left, cct)
				cct = left_rotate(nod)
			end
		end
		return cct
	end
end

redef class RopeString

	# Inserts a String `str` at position `pos`
	redef fun insert_at(str, pos)
	do
		if str.length == 0 then return self

		assert pos >= 0 and pos <= length

		if pos == length then
			var r = root
			if r isa BufferLeaf then
				var b = r.str.as(FlatBuffer)
				if r.length == b.length and r.length + str.length < b.capacity then
					b.append(str)
					return new RopeString.from_root(new BufferLeaf(b))
				end
			end
		end

		var path = node_at(pos)

		var cct: RopeNode

		if path.offset == path.leaf.length then
			cct = build_node_len_offset(path, str)
		else if path.offset == 0 then
			cct = build_node_zero_offset(path, str)
		else
			cct = build_node_other(path,str)
		end

		var st = path.stack

		if st.is_empty then return new RopeString.from_root(cct)

		var tmp = st.pop
		var last_concat: Concat

		if tmp.left then
			last_concat = new Concat(cct,tmp.node.right.as(not null))
			var pe = new PathElement(last_concat)
			pe.left = true
			st.push(pe)
		else
			last_concat = new Concat(tmp.node.left.as(not null), cct)
			var pe = new PathElement(last_concat)
			pe.right = true
			st.push(pe)
		end

		if cct isa Concat then
			var pe = new PathElement(cct)
			st.push(pe)
		end

		return new RopeString.from_root(splay(path).as(not null))
	end

end

