# Introduces a self-balancing method on Rope, using a Splay Tree
module splay_ropes

import ::standard
intrude import ::standard::ropes

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

