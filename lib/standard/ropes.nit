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

in "C header" `{

#include "nit.common.h"
#include "string._nitni.h"

typedef struct node node;
typedef struct path path;
typedef struct path_element path_element;
typedef struct iter_element iter_element;

struct node {
	// FlatString or FlatBuffer depending on the situation
	String item;
	int length;
	node* left;
	node* right;
};

struct path {
	node* leaf;
	int offset;
	path_element* tail;
};

struct path_element {
	path_element* prev;
	path_element* next;
	node* cct;
	int left;
	int right;
};

struct iter_element {
	node* item;
	int left;
	int right;
	int done;
	iter_element* next;
	iter_element* prev;
};

`}

# Used when searching for a particular node
# Returns the path to the node from the root of the rope
# Also, the node and the offset for seeked position in the rope
private extern class Path `{ path* `}

	new (lf: Leaf, off: Int, tail: PathElement)
	`{
		path* p = nit_alloc(sizeof(path));
		p->leaf = lf;
		p->offset = off;
		p->tail = tail;
		return p;
	`}

	fun leaf: Leaf `{ return recv->leaf; `}
	fun offset: Int `{ return recv->offset; `}
	fun tail: PathElement `{ return recv->tail; `}
end

# An element for a Path, has the concat node and whether or not
# left or right child was visited.
private extern class PathElement `{ path_element* `}

	new `{
		path_element* e = nit_alloc(sizeof(path_element));
		e->left = 0;
		e->right = 0;
		return e;
	`}

	fun node: Concat `{ return recv->cct; `}
	fun left: Bool `{ return recv->left; `}
	fun left=(v: Bool) `{ recv->left = v; `}
	fun right: Bool `{ return recv->right; `}
	fun right=(v: Bool) `{ recv->right = v; `}
	fun next: PathElement `{ return recv->next; `}
	fun prev: PathElement `{ return recv->prev; `}
end

# A node for a Rope
private extern class RopeNode `{ node* `}
	# Length of the node
	fun length: Int `{ return recv->length;`}

	# Transforms the current node to a Leaf.
	# This might be costly to invoke since this produces a FlatString concatenation.
	# Can be used internally to limit the growth of the Rope when working with small leaves.
	fun to_leaf: Leaf is abstract

	fun is_leaf: Bool `{ return recv->item != NULL;`}
	fun is_concat: Bool do return not is_leaf
end

# Node that represents a concatenation between two nodes (of any RopeNode type)
private extern class Concat `{ node* `}
	super RopeNode

	# Left child of the node
	fun left: RopeNode `{ return recv->left; `}
	# Right child of the node
	fun right: RopeNode `{ return recv->right; `}

	new(l: RopeNode, r: RopeNode)
	`{
		node* s = nit_alloc(sizeof(node));
		s->length = 0;
		s->item = NULL;
		s->left = l;
		s->right = r;
		if (l != NULL) { s->length += l->length;}
		if (r != NULL) { s->length += r->length;}
		return s;
	`}

	redef fun to_leaf
	do
		if left == null then
			if right == null then return new StringLeaf("".as(FlatString))
			return right.to_leaf
		end
		if right == null then return left.as(not null).to_leaf
		return new StringLeaf((left.to_leaf.str.as(FlatString) + right.to_leaf.str.as(FlatString)).as(FlatString))
	end
end

# Leaf of a Rope, contains a FlatString
private extern class Leaf `{ node* `}
	super RopeNode

	# Encapsulated FlatString in the leaf node
	fun str: FlatText is abstract
end

private extern class StringLeaf `{ node* `}
	super Leaf

	new (val: FlatString) import FlatString.length `{
		node* r = nit_alloc(sizeof(node));
		r->item = val;
		r->left = NULL;
		r->right = NULL;
		r->length = FlatString_length(val);
		return r;
	`}

	redef fun str: FlatString `{ return (FlatString)recv->item; `}

	redef fun to_leaf do return self
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
	init do from("")

	# Creates a new Rope with `s` as root
	init from(s: String) do
		if s isa RopeString then root = s.root else root = new StringLeaf(s.as(FlatString))
	end

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
	#
	# Can return a null Path if position was out of bounds.
	private fun node_at(position: Int): Path import Rope.length, Rope.root, Rope.stack_to_end, Rope.get_node_from `{
		long ropelen = Rope_length(recv);
		if(position < 0 || position > ropelen){return NULL;}
		path* p = nit_alloc(sizeof(path));
		p->tail = NULL;
		if(position == ropelen){
			Rope_stack_to_end(recv, Rope_root(recv), p);
		} else {
			Rope_get_node_from(recv, Rope_root(recv), 0, position, p);
		}
		return p;
	`}

	# Special case for when the required pos is length
	private fun stack_to_end(nod: RopeNode, st: Path) import Rope.stack_to_end, String.length, PathElement `{
		if(nod->item != NULL){
			st->leaf = nod;
			st->offset = String_length(nod->item);
			return;
		}
		node* r = nod->right;
		path_element* ele = st->tail;
		if(ele == NULL) {
			ele = new_PathElement();
			ele->cct = nod;
			ele->right = 1;
			st->tail = ele;
		} else {
			path_element* new_tail = new_PathElement();
			ele->next = new_tail;
			new_tail->prev = ele;
			st->tail = new_tail;
			new_tail->cct = nod;
			new_tail->right = 1;
		}
		if(r == NULL){return;}
		Rope_stack_to_end(recv, r, st);
	`}

	# Builds the path to Leaf at position `seek_pos`
	private fun get_node_from(node: RopeNode, curr_pos: Int, seek_pos: Int, path: Path) import PathElement, Rope.get_node_from `{
		if(curr_pos < 0){return;}
		if(node->item != NULL){
			path->leaf = node;
			path->offset = seek_pos - curr_pos;
			return;
		}
		path_element* last = new_PathElement();
		last->cct = node;
		path_element* old_last = path->tail;
		if(old_last != NULL){
			old_last->next = last;
			last->prev = old_last;
		}
		path->tail = last;
		if(node->left != NULL){
			long nxt = curr_pos + node->left->length;
			if(nxt > seek_pos){
				last->left = 1;
				Rope_get_node_from(recv, node->left, curr_pos, seek_pos, path);
			} else {
				last->right = 1;
				Rope_get_node_from(recv, node->right, nxt, seek_pos, path);
			}
		} else {
			Rope_get_node_from(recv, node->right, curr_pos, seek_pos, path);
		}
	`}

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

	redef fun to_s do return self

	redef fun empty do return once new RopeString.from("")

	redef var chars: SequenceRead[Char] = new RopeStringChars(self)

	redef fun reversed
	do
		var ret = empty
		for i in substrings do
			ret = i.as(String).reversed + ret
		end
		return ret
	end

	redef fun to_upper
	do
		var ret = empty
		for i in substrings do
			ret += i.as(String).to_upper
		end
		return ret
	end

	redef fun to_lower
	do
		var ret = empty
		for i in substrings do
			ret += i.as(String).to_lower
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
	redef fun insert_at(str, pos) import String.length, Rope.length, RopeString.from_root, StringLeaf, Rope.node_at, RopeString.generate_node_for_string, Concat, String.substring, String.substring_from `{
		long mylen = Rope_length(recv);
		long strlen = String_length(str);
		if(strlen == 0){ return recv; }
		if(mylen == 0){
			node* root = new_StringLeaf(str);
			return new_RopeString_from_root(root);
		}
		if(pos < 0 || pos > mylen) {
			printf("Assert fail.");
			exit(-1);
		}
		path* p = Rope_node_at(recv, pos);
		node* st_node = RopeString_generate_node_for_string(recv, str);
		node* cct;
		if(p->offset == 0){
			cct = new_Concat(st_node, p->leaf);
		} else if (p->offset == p->leaf->length) {
			cct = new_Concat(p->leaf, st_node);
		} else {
			long midstr = strlen - p->offset;
			String l = String_substring(l, 0, midstr);
			String r = String_substring_from(r, midstr);
			node* ll = new_StringLeaf(l);
			node* rr = new_StringLeaf(r);
			node* inter_cct = new_Concat(ll, st_node);
			cct = new_Concat(inter_cct, rr);
		}

		path_element* lst = p->tail;
		while(lst != NULL){
			if(lst->left){
				cct = new_Concat(cct, lst->cct->right);
			}else if(lst->right){
				cct = new_Concat(lst->cct->left, cct);
			}else{
				// Should not happen, but in this case, let's just leave.
				printf("Path badly set\n");
				exit(-1);
			}
			lst = lst->prev;
		}

		return new_RopeString_from_root(cct);
	`}


	# O(log(n))
	#
	#     var rope = new RopeString.from("abcd")
	#     assert rope.substring(1, 2)         ==  "bc"
	#     assert rope.substring(-1, 2)         ==  "a"
	#     assert rope.substring(1, 0)         ==  ""
	#     assert rope.substring(2, 5)         ==  "cd"
	#
	redef fun substring(pos, len) import Rope.length, RopeString.empty, Path, Rope.node_at, StringLeaf, String.substring, String.substring_from, Rope.root= `{
		long mylen = Rope_length(recv);

		if(pos < 0){
			len += pos;
			pos = 0;
		}

		path* p = Rope_node_at(recv, pos);

		node* lf = p->leaf;
		long off = p->offset;

		if((pos + len) > mylen) { len = mylen - pos; }

		if(len <= 0) { return RopeString_empty(recv); }

		if((lf->length - off) > len){
			lf = new_StringLeaf(String_substring(lf->item, off, len));
		} else {
			lf = new_StringLeaf(String_substring_from(lf->item, off));
		}

		path_element* pe = p->tail;

		while(pe != NULL){
			if(pe->right){
				pe = pe->prev;
				continue;
			}
			lf = new_Concat(lf, pe->cct->right);
			pe = pe->prev;
		}

		RopeString ret = new_RopeString_from_root(lf);

		p = Rope_node_at(ret, len-1);

		off = p->offset;
		lf = new_StringLeaf(String_substring(p->leaf->item, 0, off+1));

		pe = p->tail;
		while(pe != NULL){
			if(pe->left){
				pe = pe->prev;
				continue;
			}
			lf = new_Concat(pe->cct->left, lf);
			pe = pe->prev;
		}

		Rope_root__assign(ret, lf);

		return ret;
	`}

	private fun generate_node_for_string(str: String): RopeNode
	do
		if str isa FlatString then return new StringLeaf(str)
		return str.as(RopeString).root
	end

end

redef class FlatString

	redef fun insert_at(s, pos)
	do

		if pos == 0 then
			var r = new RopeString.from(s)
			return r + self
		end
		if pos == length then
			var r = new RopeString.from(self)
			return r + s
		end

		var l = substring(0,pos)
		var r = substring_from(pos)
		var ret: String = new RopeString.from(l)
		ret += s
		return ret + r
	end

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
private extern class IteratorElement `{ iterator_element* `}

	new(e: RopeNode)
	`{
		if(recv->item){
			recv->left = 1;
			recv->right = 1;
		} else {
			recv->left = 0;
			recv->right = 0;
		}
		recv->item = e;
	`}

	# The node being visited
	fun node: RopeNode `{ return recv->item; `}
	# If the node has a left child, was it visited ?
	fun left: Bool `{ return recv->left; `}

	fun left=(l: Bool) `{ recv->left = l; `}
	# If the node has a right child, was it visited ?
	fun right: Bool `{ return recv->right; `}

	fun right=(r: Bool) `{ recv->right - r;`}
	# Was the current node visited ?
	fun done: Bool `{ return recv->done; `}

	fun done=(v: Bool) `{ recv->done = v; `}
	# Pointer to the previous element
	fun prev `{ return recv->prev; `}

	fun prev=(o: IteratorElement) `{ recv->prev = o; `}
	# Pointer to the next element
	fun next `{ return recv->next; `}

	fun next=(o: IteratorElement) `{ recv->next = o; `}
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
		substring = substring.substring(min, length)
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
		if pos >= (leaves.index + str.length - 1) then return
		str = str.substring(0, (pos - leaves.index + 1))
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

