# This file is part of NIT ( http://www.nitlanguage.org ).
#
# This file is free software, which comes along with NIT.  This software is
# distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
# without  even  the implied warranty of  MERCHANTABILITY or  FITNESS FOR A
# PARTICULAR PURPOSE.  You can modify it if you want,  provided this header
# is kept unaltered, and a notification of the changes is added.
# You  are  allowed  to  redistribute it and sell it, alone or as a part of
# another product.

# Nit implementation of the Ropes (see Ropes : An Alternative to Strings,
# SOFTWARE - PRACTICE AND EXPERIENCE, VOL. 25(12), 1315 - 1330 (DECEMBER 1995)
# Hans. J Boehm, Russ Atkinson and Michael Plass)
#
# A rope is a kind of string but instead of being flat, it relies on a binary tree structure to store data.
module ropes

intrude import string

# Used when searching for a particular node
# Returns the path to the node from the root of the rope
# Also, the node and the offset for seeked position in the rope
private class Path
	# Leaf found
	var leaf: Leaf
	# Offset in leaf
	var offset: Int
	# Stack of the nodes traversed, and the path used
	var stack: List[PathElement]
end

# An element for a Path, has the concat node and whether or not
# left or right child was visited.
private class PathElement
	# Visited node
	var node: Concat
	# Was the left child visited ?
	var left = false
	# Was the right child visited ?
	var right = false
end

# A node for a Rope
private abstract class RopeNode
	# Length of the node
	var length = 0

	fun to_leaf: Leaf is abstract
end

redef class FlatText

	private fun lazy_substring(from: Int, length: Int): FlatString is abstract

	private fun lazy_substring_from(from: Int): FlatString is abstract
end

redef class FlatBuffer

	# Same as to_s, only will not copy self before returning a String.
	private fun lazy_to_s(len: Int): FlatString
	do
		return new FlatString.with_infos(items, len, 0, length - 1)
	end

	redef fun append(o)
	do
		if o isa RopeString then
			for i in o.substrings do
				self.append(i)
			end
		else
			super
		end
	end

	redef fun lazy_substring(from,length)
	do
		return new FlatString.with_infos(items, length, from, from + length - 1)
	end

	redef fun lazy_substring_from(from)
	do
		var newlen = length - from
		return new FlatString.with_infos(items, newlen, from, from + newlen - 1)
	end

end

# Node that represents a concatenation between two nodes (of any RopeNode type)
private class Concat
	super RopeNode

	# Left child of the node
	var left: nullable RopeNode = null
	# Right child of the node
	var right: nullable RopeNode = null

	init(l: nullable RopeNode, r: nullable RopeNode)
	do
		left = l
		right = r
		if left != null then length += left.length
		if right != null then length += right.length
	end

	redef fun to_leaf
	do
		if left == null then
			if right == null then return empty_leaf
			return right.to_leaf
		end
		if right == null then return left.as(not null).to_leaf
		if left.length + right.length < buf_len then
			var b = new FlatBuffer.with_capacity(buf_len)
			b.append(left.to_leaf.str)
			b.append(right.to_leaf.str)
			return new BufferLeaf(b)
		else
			var b = new FlatBuffer.with_capacity(left.length + right.length)
			b.append(left.to_leaf.str)
			b.append(right.to_leaf.str)
			return new StringLeaf(b.lazy_to_s(b.length))
		end
	end
end

# Leaf of a Rope, contains a FlatString
private abstract class Leaf
	super RopeNode

	var str: FlatText

	redef fun to_leaf do return self
end

private class StringLeaf
	super Leaf

	init(val: FlatString) do
		self.str = val
		length = str.length
	end
end

private class BufferLeaf
	super Leaf

	init(val: FlatBuffer) do
		self.str = val
		length = str.length
	end

end

# Basic structure, binary tree with a root node.
#
# Also shared services by subsequent implementations.
abstract class Rope
	super Text

	# Root node, entry point of a Rope.
	private var root: RopeNode

	# Cached version of self as a flat String
	private var str_representation: nullable NativeString = null

	# Empty Rope
	init do root = new BufferLeaf(new FlatBuffer.with_capacity(buf_len))

	# Creates a new Rope with `s` as root
	init from(s: String) do end

	private init from_root(r: RopeNode)
	do
		root = r
	end

	redef fun length do return root.length

	# Iterator on the nodes of the rope, in forward postfix order
	private fun postfix(from: Int): Postfix do return new Postfix.from(self, from)

	# Iterator on the leaves of the rope, forward order
	private fun leaves(from: Int): LeavesIterator do return new LeavesIterator(self, from)

	# Iterator on the substrings from 0, in forward order
	redef fun substrings do return new SubstringsIterator(self, 0)

	# Iterator on the substrings, starting at position `from`, in forward order
	fun substrings_from(from: Int): IndexedIterator[Text] do return new SubstringsIterator(self, from)

	# Iterator on the nodes of the rope, in backwards postfix order
	private fun reverse_postfix(from: Int): ReversePostfix do return new ReversePostfix.from(self, from)

	# Iterator on the leaves of the rope, backwards order
	private fun reverse_leaves(from: Int): ReverseLeavesIterator do return new ReverseLeavesIterator(self,from)

	# Iterator on the substrings, in reverse order
	fun reverse_substrings: IndexedIterator[Text] do return new ReverseSubstringsIterator(self, length-1)

	# Iterator on the substrings, in reverse order, starting iteration at position `from`
	fun reverse_substrings_from(from: Int): IndexedIterator[Text] do return new ReverseSubstringsIterator(self, from)

	redef fun output
	do
		for i in substrings do
			i.output
		end
	end

	redef fun to_cstring
	do
		if str_representation != null then return str_representation.as(not null)

		var native_final_str = calloc_string(length + 1)

		native_final_str[length] = '\0'

		if self.length == 0 then
			str_representation = native_final_str
			return native_final_str
		end

		var offset = 0

		for i in substrings do
			var str = i.flatten
			if str isa FlatString then str.items.copy_to(native_final_str, str.length, str.index_from, offset)
			offset += i.length
		end

		str_representation = native_final_str

		return native_final_str
	end

	# Path to the Leaf for `position`
	private fun node_at(position: Int): Path
	do
		assert position >= 0 and position <= length
		if position == length then
			var st = new List[PathElement]
			stack_to_end(root,st)
			if not st.is_empty then
				var lst = st.last
				var lf = lst.node.right
				if lf != null then
					return new Path(lf.as(Leaf), lf.length, st)
				else
					lf = lst.node.left
					return new Path(lf.as(Leaf), lf.length, st)
				end
			else
				return new Path(root.as(Leaf), length, st)
			end
		end
		return get_node_from(root.as(not null), 0, position, new List[PathElement])
	end

	# Special case for when the required pos is length
	private fun stack_to_end(nod: RopeNode, st: List[PathElement])
	do
		if nod isa Leaf then return
		var n = nod.as(Concat)
		var r = n.right
		var ele = new PathElement(n)
		ele.right = true
		st.push(ele)
		if r != null then
			stack_to_end(r, st)
		end
		return
	end

	# Builds the path to Leaf at position `seek_pos`
	private fun get_node_from(node: RopeNode, curr_pos: Int, seek_pos: Int, stack: List[PathElement]): Path
	do
		assert curr_pos >= 0
		if node isa Leaf then return new Path(node, seek_pos - curr_pos, stack)
		node = node.as(Concat)

		if node.left != null then
			var next_pos = curr_pos + node.left.length
			stack.add(new PathElement(node))
			if next_pos > seek_pos then
				stack.last.left = true
				return get_node_from(node.left.as(not null), curr_pos, seek_pos, stack)
			end
			stack.last.right = true
			return get_node_from(node.right.as(not null), next_pos, seek_pos, stack)
		else
			var vis = new PathElement(node)
			vis.right = true
			stack.add(vis)
			return get_node_from(node.right.as(not null), curr_pos, seek_pos, stack)
		end
	end

	redef fun ==(o)
	do
		if not o isa Text then return false
		if o.length != self.length then return false
		var oit = o.chars.iterator
		for i in self.chars.iterator do
			if i != oit.item then return false
			oit.next
		end
		return true
	end
end

# Rope that cannot be modified
class RopeString
	super Rope
	super String

	init from(s) do
		if s.length < buf_len then
			var b = new FlatBuffer.with_capacity(buf_len)
			b.append(s)
			root = new BufferLeaf(b)
		else
			if s isa RopeString then root = s.root else root = new StringLeaf(s.as(FlatString))
		end
	end

	redef fun to_s do return self

	redef fun empty do return once new RopeString.from("")

	redef var chars: SequenceRead[Char] = new RopeStringChars(self)

	redef fun reversed
	do
		var ret = empty.as(RopeString)
		for i in substrings do
			ret = ret.prepend(i.reversed.to_s).as(RopeString)
		end
		return ret
	end

	redef fun to_upper
	do
		var ret = empty
		for i in substrings do
			ret += i.to_upper
		end
		return ret
	end

	redef fun to_lower
	do
		var ret = empty
		for i in substrings do
			ret += i.to_lower
		end
		return ret
	end

	redef fun +(o) do return insert_at(o.to_s, length)

	redef fun *(n)
	do
		var ret = new RopeString.from("")
		for i in [0..n[ do
			ret = (ret + self).as(RopeString)
		end
		return ret
	end

	# Inserts a String `str` at position `pos`
	redef fun insert_at(str, pos)
	do
		if str.length == 0 then return self
		if self.length == 0 then return new RopeString.from(str)

		assert pos >= 0 and pos <= length

		var path = node_at(pos)

		var cct: RopeNode

		if path.offset == 0 then
			cct = build_node_zero_offset(path, str)
		else if path.offset == path.leaf.length then
			cct = build_node_len_offset(path, str)
			#if str isa FlatString then last_concat.right = new Leaf(str) else last_concat.right = str.as(RopeString).root
			#last_concat.left = path.leaf
		else
			cct = build_node_other(path,str)
			#var s = path.leaf.str
			#var l_half = s.substring(0, s.length - path.offset)
			#var r_half = s.substring_from(s.length - path.offset)
			#var cct = new Concat
			#cct.right = new Leaf(r_half.as(FlatString))
			#last_concat.left = new Leaf(l_half.as(FlatString))
			#if str isa FlatString then last_concat.right = new Leaf(str) else last_concat.right = str.as(RopeString).root
			#cct.left = last_concat
			#last_concat = cct
		end

		if path.stack.is_empty then return new RopeString.from_root(cct)

		var tmp = path.stack.pop
		var last_concat: Concat

		if tmp.left then
			last_concat = new Concat(cct,tmp.node.right.as(not null))
		else
			last_concat = new Concat(tmp.node.left.as(not null), cct)
		end

		for i in path.stack.reverse_iterator do
			var nod: Concat
			if i.left then
				nod = new Concat(last_concat, i.node.right.as(not null))
			else
				nod = new Concat(i.node.left.as(not null), last_concat)
			end
			last_concat = nod
		end

		return new RopeString.from_root(last_concat)
	end

	private fun build_node_zero_offset(path: Path, s: String): RopeNode
	do
		var finlen = path.leaf.length + s.length
		if finlen <= buf_len then
			var b = new FlatBuffer.with_capacity(buf_len)
			b.append(s)
			b.append(path.leaf.str)
			if finlen == buf_len then return new StringLeaf(b.lazy_to_s(finlen))
			return new BufferLeaf(b)
		end
		var rht = path.leaf
		var lft: RopeNode
		if s isa FlatString then
			if s.length > buf_len then
				lft = new StringLeaf(s)
			else
				var b = new FlatBuffer
				b.append(s)
				lft = new BufferLeaf(b)
			end
		else
			lft = s.as(RopeString).root
		end
		return new Concat(lft, rht)
	end

	private fun build_node_len_offset(path: Path, s: String): RopeNode
	do
		var leaf = path.leaf
		if leaf isa BufferLeaf then
			if s.length > buf_len then
				if s isa FlatString then
					return new StringLeaf(s)
				else
					return s.as(Rope).root
				end
			end
			var finlen = leaf.length + s.length
			var buf = leaf.str.as(FlatBuffer)
			var cap = buf.capacity
			# Meaning the buffer was modified elsewhere
			# Therefore, we create a new one
			if leaf.length != buf.length then
				var b = new FlatBuffer.with_capacity(buf_len)
				b.append(buf.lazy_to_s(leaf.length))
				buf = b
			end
			if finlen <= cap then
				buf.append(s)
				if finlen == buf_len then return new StringLeaf(buf.lazy_to_s(finlen))
				return new BufferLeaf(buf)
			else
				var l_len = finlen - cap
				buf.append(s.substring(0,l_len))
				var b2 = new FlatBuffer.with_capacity(buf_len)
				b2.append(s.substring_from(l_len))
				var left_leaf = new StringLeaf(buf.lazy_to_s(buf.length))
				var right_leaf = new BufferLeaf(b2)
				var cct = new Concat(left_leaf, right_leaf)
				return cct
			end
		else
			var lft = leaf
			var rht: RopeNode
			if s.length >= buf_len then
				if s isa FlatString then rht = new StringLeaf(s) else rht = s.as(Rope).root
			else
				var buf = new FlatBuffer.with_capacity(buf_len)
				buf.append(s)
				rht = new BufferLeaf(buf)
			end
			return new Concat(lft,rht)
		end
	end

	private fun build_node_other(path: Path,str: String): RopeNode
	do
		var lf = path.leaf
		var s: FlatString
		if lf isa BufferLeaf then
			var b = lf.str.as(FlatBuffer)
			s = b.lazy_to_s(lf.length)
		else
			s = lf.str.as(FlatString)
		end
		var l_str = s.lazy_substring(0, path.offset)
		var r_str = s.lazy_substring_from(path.offset)
		if s.length + str.length < buf_len then
			var buf = new FlatBuffer.with_capacity(buf_len)
			buf.append(l_str)
			buf.append(str)
			buf.append(r_str)
			return new BufferLeaf(buf)
		end
		var child: RopeNode
		if str isa FlatString then child = new StringLeaf(str) else child = str.as(Rope).root
		var l_cct = new Concat(new StringLeaf(l_str.as(FlatString)), child)
		var r_cct = new Concat(l_cct, new StringLeaf(r_str.as(FlatString)))
		return r_cct
	end

	# Adds `s` at the beginning of self
	redef fun prepend(s) do return insert_at(s, 0)

	# Adds `s` at the end of self
	redef fun append(s)
	do
		return insert_at(s, length)
	end

	# O(log(n))
	#
	#     var rope = new RopeString.from("abcd")
	#     assert rope.substring(1, 2)         ==  "bc"
	#     assert rope.substring(-1, 2)         ==  "a"
	#     assert rope.substring(1, 0)         ==  ""
	#     assert rope.substring(2, 5)         ==  "cd"
	#
	redef fun substring(pos, len)
	do
		if pos < 0 then
			len += pos
			pos = 0
		end

		if pos + len > length then len = length - pos

		if len <= 0 then return new RopeString

		var path = node_at(pos)

		var lf = path.leaf
		var offset = path.offset

		var s: FlatString
		if lf isa StringLeaf then
			s = lf.str.as(FlatString)
		else
			s = lf.str.as(FlatBuffer).lazy_to_s(lf.length)
		end

		if path.leaf.str.length - offset > len then
			lf = new StringLeaf(s.substring(offset,len).as(FlatString))
		else
			lf = new StringLeaf(s.substring_from(offset).as(FlatString))
		end

		var nod: RopeNode = lf

		var lft: nullable RopeNode
		var rht: nullable RopeNode

		for i in path.stack.reverse_iterator do
			if i.right then continue
			lft = nod
			rht = i.node.right
			nod = new Concat(lft, rht)
		end

		var ret = new RopeString
		ret.root = nod

		path = ret.node_at(len-1)

		offset = path.offset

		lf = path.leaf

		if lf isa StringLeaf then
			s = lf.str.as(FlatString)
		else
			s = lf.str.as(FlatBuffer).lazy_to_s(lf.length)
		end

		nod = new StringLeaf(s.substring(0, offset+1).as(FlatString))

		for i in path.stack.reverse_iterator do
			if i.left then continue
			rht = nod
			lft = i.node.left
			nod = new Concat(lft, rht)
		end

		ret.root = nod

		return ret
	end
end

redef class FlatString

	redef fun +(o)
	do
		if (self.length + o.length) > cct_threshold then
			return new RopeString.from(self) + o
		end
		return super
	end

	redef fun append(s) do return (new RopeString.from(self)) + s

	redef fun prepend(s) do return (new RopeString.from(self)).prepend(s)

	redef fun insert_at(s, pos)
	do
		if pos == 0 then return prepend(s)
		if pos == length then return append(s)

		var l = substring(0,pos)
		var r = substring_from(pos)
		var ret: String = new RopeString.from(l)
		ret += s
		return ret + r
	end

	redef fun lazy_substring(from, len) do return substring(from,len).as(FlatString)

	redef fun lazy_substring_from(from) do return substring_from(from).as(FlatString)

end

private class RopeStringChars
	super SequenceRead[Char]

	var tgt: Rope

	redef fun [](pos)
	do
		assert pos < tgt.length
		var path = tgt.node_at(pos)
		return path.leaf.str.chars[path.offset]
	end

	redef fun iterator do return iterator_from(0)

	redef fun iterator_from(pos) do return new RopeCharIterator(tgt, pos)

	redef fun reverse_iterator do return reverse_iterator_from(tgt.length-1)

	redef fun reverse_iterator_from(pos) do return new ReverseRopeCharIterator(tgt, pos)
end

# Used to iterate on a Rope
private class IteratorElement

	init(e: RopeNode)
	do
		if e isa Leaf then
			left = true
			right = true
		end
		node = e
	end

	# The node being visited
	var node: RopeNode
	# If the node has a left child, was it visited ?
	var left = false
	# If the node has a right child, was it visited ?
	var right = false
	# Was the current node visited ?
	var done = false
end

# Simple Postfix iterator on the nodes of a Rope
private class Postfix
	super IndexedIterator[RopeNode]

	# Target Rope to iterate on
	var target: Rope

	# Current position in Rope
	var pos: Int

	# Visited nodes
	var stack = new List[IteratorElement]

	init from(tgt: Rope, pos: Int)
	do
		self.target = tgt
		self.pos = pos
		if pos < 0 or pos >= tgt.length then return
		var path = tgt.node_at(pos)
		self.pos -= path.offset
		for i in path.stack do
			var item = new IteratorElement(i.node)
			item.left = true
			if i.right then item.right = true
			stack.push item
		end
		var item = new IteratorElement(path.leaf)
		item.done = true
		stack.push item
	end

	redef fun item
	do
		assert is_ok
		return stack.last.node
	end

	redef fun is_ok do return not stack.is_empty

	redef fun index do return pos

	redef fun next do
		if stack.is_empty then return
		if pos > target.length-1 then
			stack.clear
			return
		end
		var lst = stack.last
		if lst.done then
			if lst.node isa Leaf then
				pos += lst.node.length
			end
			stack.pop
			next
			return
		end
		if not lst.left then
			lst.left = true
			var nod = lst.node
			if nod isa Concat and nod.left != null then
				stack.push(new IteratorElement(nod.left.as(not null)))
				next
				return
			end
		end
		if not lst.right then
			lst.right = true
			var nod = lst.node
			if nod isa Concat and nod.right != null then
				stack.push(new IteratorElement(nod.right.as(not null)))
				next
				return
			end
		end
		lst.done = true
	end
end

# Iterates on the leaves (substrings) of the Rope
class LeavesIterator
	super IndexedIterator[Leaf]

	private var nodes: Postfix

	init(tgt: Rope, pos: Int)
	do
		nodes = tgt.postfix(pos)
	end

	redef fun is_ok do return nodes.is_ok

	redef fun item
	do
		assert is_ok
		return nodes.item.as(Leaf)
	end

	redef fun index do return nodes.index

	redef fun next
	do
		while nodes.is_ok do
			nodes.next
			if nodes.is_ok and nodes.item isa Leaf then break
		end
	end
end

# Uses the leaves and calculates a new substring on each iteration
class SubstringsIterator
	super IndexedIterator[Text]

	private var nodes: IndexedIterator[Leaf]

	# Current position in Rope
	var pos: Int

	# Current substring, computed from the current Leaf and indexes
	var substring: Text

	init(tgt: Rope, pos: Int)
	do
		nodes = tgt.leaves(pos)
		self.pos = pos
		if pos < 0 or pos >= tgt.length then return
		make_substring
	end

	# Compute the bounds of the current substring and makes the substring
	private fun make_substring
	do
		substring = nodes.item.str
		var min = 0
		var length = substring.length
		if nodes.index < pos then
			min = pos - nodes.index
		end
		substring = s.lazy_substring(min, length)
	end

	redef fun is_ok do return nodes.is_ok

	redef fun item
	do
		assert is_ok
		return substring
	end

	redef fun index do return pos

	redef fun next
	do
		pos += substring.length
		nodes.next
		if nodes.is_ok then make_substring
	end

end

class RopeCharIterator
	super IndexedIterator[Char]

	var substrings: IndexedIterator[Text]

	var pos: Int

	var max: Int

	var substr_iter: IndexedIterator[Char]

	init(tgt: Rope, from: Int)
	do
		substrings = tgt.substrings_from(from)
		max = tgt.length - 1
		if not substrings.is_ok then
			pos = tgt.length
			return
		end
		pos = from
		substr_iter = substrings.item.chars.iterator
	end

	redef fun item do return substr_iter.item

	redef fun is_ok do return pos <= max

	redef fun index do return pos

	redef fun next
	do
		pos += 1
		if substr_iter.is_ok then
			substr_iter.next
		end
		if not substr_iter.is_ok then
			substrings.next
			if substrings.is_ok then
				substr_iter = substrings.item.chars.iterator
			end
		end
	end
end

private class ReversePostfix
	super IndexedIterator[RopeNode]

	var target: Rope

	var pos: Int

	var min = 0

	var stack = new List[IteratorElement]

	init from(tgt: Rope, pos: Int)
	do
		self.pos = pos
		target = tgt
		if pos < 0 or pos >= tgt.length then return
		var path = tgt.node_at(pos)
		self.pos -= path.offset
		for i in path.stack do
			var elemt = new IteratorElement(i.node)
			elemt.right = true
			if i.left then
				elemt.left = true
			end
			stack.push elemt
		end
		stack.push(new IteratorElement(path.leaf))
		stack.last.done = true
	end

	redef fun item do
		assert is_ok
		return stack.last.node
	end

	redef fun is_ok do return not stack.is_empty

	redef fun index do return pos

	redef fun next
	do
		if stack.is_empty then return
		if pos < min then
			stack.clear
			return
		end
		var lst = stack.last
		if lst.done then
			stack.pop
			next
			return
		end
		if not lst.right then
			var nod = lst.node.as(Concat)
			var rgt = nod.right
			lst.right = true
			if rgt != null then
				stack.push(new IteratorElement(rgt))
				next
				return
			end
		end
		if not lst.left then
			var nod = lst.node.as(Concat)
			var lft = nod.left
			lst.left = true
			if lft != null then
				stack.push(new IteratorElement(lft))
				next
				return
			end
		end
		if lst.node isa Leaf then pos -= lst.node.length
		lst.done = true
	end
end

private class ReverseLeavesIterator
	super IndexedIterator[Leaf]

	var nodes: ReversePostfix

	init(tgt: Rope, from: Int)
	do
		nodes = tgt.reverse_postfix(from)
	end

	redef fun is_ok do return nodes.is_ok

	redef fun item do
		assert is_ok
		return nodes.item.as(Leaf)
	end

	redef fun next do
		while nodes.is_ok do
			nodes.next
			if nodes.is_ok then if nodes.item isa Leaf then break
		end
	end

	redef fun index do return nodes.index

end

private class ReverseSubstringsIterator
	super IndexedIterator[Text]

	var leaves: ReverseLeavesIterator

	var pos: Int

	var str: Text

	init(tgt: Rope, from: Int)
	do
		leaves = tgt.reverse_leaves(from)
		pos = from
		if not leaves.is_ok then return
		str = leaves.item.str
		make_substring
	end

	fun make_substring
	do
		var l = leaves.item
		var s = l.str
		if pos > (leaves.index + l.length - 1) then return
		str = s.lazy_substring(0, (pos - leaves.index + 1))
	end

	redef fun is_ok do return leaves.is_ok

	redef fun item do
		assert is_ok
		return str
	end

	redef fun index do return pos

	redef fun next do
		pos -= str.length
		leaves.next
		if not leaves.is_ok then return
		str = leaves.item.str
		make_substring
	end
end

private class ReverseRopeCharIterator
	super IndexedIterator[Char]

	var substrs: IndexedIterator[Text]

	var pos: Int

	var subiter: IndexedIterator[Char]

	init(tgt: Rope, from: Int)
	do
		substrs = tgt.reverse_substrings_from(from)
		if not substrs.is_ok then
			pos = -1
			return
		end
		subiter = substrs.item.chars.reverse_iterator
		pos = from
	end

	redef fun is_ok do return pos >= 0

	redef fun item do
		assert is_ok
		return subiter.item
	end

	redef fun index do return pos

	redef fun next do
		pos -= 1
		if subiter.is_ok then subiter.next
		if not subiter.is_ok then
			if substrs.is_ok then substrs.next
			if substrs.is_ok then subiter = substrs.item.chars.reverse_iterator
		end
	end
end

# Returns a Leaf containing "" only
private fun empty_leaf: Leaf do return once new Leaf("".as(FlatString))

# Threshold after which a concatenation will produce a Rope instead of a Flat
private fun cct_threshold: Int do return 50

# Threshold below which an addition to a Leaf of the Rope will produce a concatenation of Flats
private fun leaf_threshold: Int do return 30

# Standard length of a Leaf's buffer
private fun buf_len: Int do return 150

