# Parses an LTL Property and checks for discrepancies in the linked trace if any

import ltl_parser
import ltl_lexer
import state_analysis

class LTLAnalysis

	init(file: String, states: Sequence[State])
	do
		var readall = new IFStream.open(file).read_all
		var lex = new Lexer_ltl(readall)
		var tks = lex.lex
		var prsr = new Parser_ltl
		prsr.tokens.add_all(tks)
		var top_node = prsr.parse
		var visit = new LTLVisitor
		visit.states = states
		visit.enter_visit(top_node)
		var checkup = new LTLValidationVisitor
		checkup.states = visit.states
		checkup.enter_visit(top_node)
	end

end

class LTLVisitor
	super Visitor

	var states: nullable Sequence[State] = null

	redef fun visit(n) do n.accept_visit_LTL(self, 0)

end

class LTLValidationVisitor
	super LTLVisitor

	redef fun visit(n) do n.accept_ltl_checker(self, 0)

end

class LintVisitor
	super Visitor

	redef fun visit(n) do n.accept_printer(self)
end

redef class Ns
	
	redef fun accept_ltl_checker(v, state_id)
	do
		n_ltlexp.accept_ltl_checker(v, 0)
	end

end

redef class Node

	var state_value = new HashMap[Int, Bool]

	fun accept_visit_LTL(v: LTLVisitor, state_index: Int): Bool do
		for i in children do
			i.accept_visit_LTL(v, state_index)
		end
		return true
	end

	fun accept_ltl_checker(v: LTLValidationVisitor, state_id: Int)
	do
		for i in children do
			i.accept_ltl_checker(v, state_id)
		end
	end

	fun accept_printer(v: LintVisitor)
	do
		for i in children do
			if i isa NToken then
				printn i.text
				printn " "
			else
				v.visit(i.as(not null))
			end
		end
	end

	fun print_tks
	do
		(new LintVisitor).visit(self)
	end

end

redef class Nltlexp

	fun value(v: LTLVisitor, state_id: Int): String
	do
		print "Tried to invoke value function on type : {class_name}"
		print "Unsupported function on LTL properties : value"
		abort
	end

end

redef class Nltlexp_simple

	redef fun accept_visit_LTL(v, state_index)
	do
		if n_simple_expr3.value(v, state_index) == "TRUE" then
			state_value[state_index] = true
			return true
		end
		state_value[state_index] = false
		return false
	end

	redef fun accept_ltl_checker(v, state_id)
	do
		printn "Boolean expression at {state_id+1} is {state_value[state_id]}: \""
		print_tks
		printn "\"\n"
		n_simple_expr3.accept_ltl_checker(v, state_id)
	end

end

redef class Nltlexp_globally

	redef fun accept_visit_LTL(v, state_index)
	do
		for i in [state_index..v.states.length[ do
			if not n_ltlexp4.accept_visit_LTL(v, i) then
				state_value[state_index] = false
				return false
			end
		end
		state_value[state_index] = true
		return true
	end

	redef fun accept_ltl_checker(v, state_id)
	do
		for i in [state_id..v.states.length[ do
			if not state_value[i] then
				printn "Error in G property : \""
				print_tks
				printn "\" at state {state_id+1}\n"
				for j in [i .. v.states.length[ do
					if not n_ltlexp4.state_value[j] then
						n_ltlexp4.accept_ltl_checker(v, j)
						return
					end
				end
				return
			end
		end
	end

end

redef class Nltlexp_until

	redef fun accept_visit_LTL(v, state_index)
	do
		for i in [state_index .. v.states.length[ do
			if not n_ltlexp4.accept_visit_LTL(v, i) then 
				state_value[state_index] = true
				return true
			end
			if not n_ltlexp3.accept_visit_LTL(v, i) then
				state_value[state_index] = false
				return false
			end
		end
		state_value[state_index] = true
		return true
	end

	redef fun accept_ltl_checker(v, state_id)
	do
		for i in [state_id..v.states.length[ do
			if not state_value[i] then
				print "Error on U expression : \""
				print_tks
				print "\" at state {state_id+1}\n"
				if not n_ltlexp4.state_value[i] then n_ltlexp4.accept_ltl_checker(v, i)
				if not n_ltlexp3.state_value[i] then n_ltlexp3.accept_ltl_checker(v, i)
				return
			end
		end
	end

end

redef class Nltlexp_finally

	redef fun accept_visit_LTL(v, state_index)
	do
		for i in [state_index..v.states.length[ do
			if n_ltlexp4.accept_visit_LTL(v,i) then
				state_value[state_index] = true
				return true
			end
		end
		state_value[state_index] = false
		return false
	end

	redef fun accept_ltl_checker(v, state_id)
	do
		if not state_value[state_id] then
			printn "Error on F expression \""
			print_tks
			printn "\" is never validated from state {state_id+1} and onwards.\n"
			for i in [state_id .. v.states.length[ do
				n_ltlexp4.accept_ltl_checker(v,i)
			end
			return
		end
	end

end

redef class Nltlexp_not

	redef fun accept_visit_LTL(v, state_index)
	do
		var res = not n_ltlexp2.accept_visit_LTL(v, state_index)
		if res then
			state_value[state_index] = true
		else
			state_value[state_index] = false
		end
		return res
	end

	redef fun accept_ltl_checker(v, state_id)
	do
		if not state_value[state_id] then
			printn "! Expression \""
			print_tks
			printn "\" invalid on state {state_id+1}\n"
			return
		end
	end

end

redef class Nltlexp_par

	redef fun accept_visit_LTL(v, state_index)
	do
		var res = n_ltlexp.accept_visit_LTL(v, state_index)
		if res then
			state_value[state_index] = true
		else
			state_value[state_index] = false
		end
		return res

	end

	redef fun accept_ltl_checker(v, state_id)
	do
		if not state_value[state_id] then
			printn "() Expression \""
			print_tks
			printn "\" invalid on state {state_id+1}\n"
			n_ltlexp.accept_ltl_checker(v, state_id)
			return
		end
	end

end

redef class Nltlexp_next

	redef fun accept_visit_LTL(v, state_index)
	do
		var res = n_ltlexp4.accept_visit_LTL(v, state_index + 1)
		if res then
			state_value[state_index] = true
		else
			state_value[state_index] = false
		end
		return res

	end

	redef fun accept_ltl_checker(v, state_id)
	do
		if not state_value[state_id] then
			printn "X Expression \""
			print_tks
			printn "\" invalid on state {state_id+1}\n"
			n_ltlexp4.accept_ltl_checker(v, state_id + 1)
			return
		end
	end

end

redef class Nltlexp_and

	redef fun accept_visit_LTL(v, state_index)
	do
		if n_ltlexp2.accept_visit_LTL(v, state_index) then
			if n_ltlexp3.accept_visit_LTL(v, state_index) then
				state_value[state_index] = true
				return true
			end
		end
		state_value[state_index] = false
		return false
	end

	redef fun accept_ltl_checker(v, state_id)
	do
		if not state_value[state_id] then
			printn "& Expression \""
			print_tks
			printn "\" invalid on state {state_id+1}\n"
			if not n_ltlexp2.state_value[state_id] then
				n_ltlexp2.accept_ltl_checker(v, state_id)
			end
			if not n_ltlexp3.state_value[state_id] then
				n_ltlexp3.accept_ltl_checker(v, state_id)
			end
			return
		end
	end

end

redef class Nltlexp_or

	redef fun accept_visit_LTL(v, state_index)
	do
		if n_ltlexp2.accept_visit_LTL(v, state_index) then
			state_value[state_index] = true
			return true
		end
		if n_ltlexp3.accept_visit_LTL(v, state_index) then
			state_value[state_index] = true
			return true
		end
		state_value[state_index] = false
		return false
	end

	redef fun accept_ltl_checker(v, state_id)
	do
		if not state_value[state_id] then
			printn "| Expression \""
			print_tks
			printn "\" invalid on state {state_id+1}\n"
			n_ltlexp2.accept_ltl_checker(v, state_id)
			n_ltlexp3.accept_ltl_checker(v, state_id)
			return
		end
	end

end

redef class Nltlexp_then

	redef fun accept_visit_LTL(v, state_index)
	do
		if n_ltlexp2.accept_visit_LTL(v, state_index) then
			if not n_ltlexp3.accept_visit_LTL(v, state_index) then
				state_value[state_index] = false
				return false
			end
		end
		state_value[state_index] = true
		return true
	end

	redef fun accept_ltl_checker(v, state_id)
	do
		if not state_value[state_id] then
			printn "-> Expression \""
			print_tks
			printn "\" invalid on state {state_id+1}\n"
			n_ltlexp2.accept_ltl_checker(v, state_id)
			print "->"
			n_ltlexp3.accept_ltl_checker(v, state_id)
			return
		end
	end

end

redef class Nltlexp_iff

	redef fun accept_visit_LTL(v, state_index)
	do
		if n_ltlexp2.accept_visit_LTL(v, state_index) and not n_ltlexp3.accept_visit_LTL(v, state_index) then
			state_value[state_index] = false
			return false
		end
		state_value[state_index] = true
		return true
	end

	redef fun accept_ltl_checker(v, state_id)
	do
		if not state_value[state_id] then
			printn "<-> Expression \""
			print_tks
			printn "\" invalid on state {state_id+1}\n"
			n_ltlexp2.accept_ltl_checker(v, state_id)
			print "<->"
			n_ltlexp3.accept_ltl_checker(v, state_id)
			return
		end
	end

end

redef class Nltlexp_enum

	var enumvals: nullable HashSet[String] = null

	redef fun value(v, state_index)
	do
		var value = v.states[state_index].get_var(n_id.text)
		if value == null then
			print "Error, cannot find variable {n_id.text} at state {state_index+1}"
			abort
		end
		if enumvals == null then
			enumvals = new HashSet[String]
			n_enum_block.get_ids(enumvals.as(not null))
		end
		if enumvals.has(value) then
			state_value[state_index] = true
			return "TRUE"
		end
		state_value[state_index] = false
		return "FALSE"
	end

	redef fun accept_ltl_checker(v, state_id)
	do
		print "Expression in enum is {state_value[state_id]} : "
		printn "{n_id.text} is not in \{ "
		for i in enumvals.as(not null) do
			printn i
			printn ", "
		end
		printn "\}\nSince {n_id.text} = {v.states[state_id].get_var(n_id.text)} at state {state_id+1}\n"
	end

end

redef class Nltlexp_eq

	redef fun value(v, state_index)
	do
		var lvar = n_simple_expr3.value(v, state_index)
		var rvar = n_simple_expr4.value(v, state_index)
		if lvar.is_numeric and rvar.is_numeric then
			if lvar.to_i == rvar.to_i then
				state_value[state_index] = true
				return "TRUE"
			end
			state_value[state_index] = false
			return "FALSE"
		else
			if lvar == rvar then
				state_value[state_index] = true
				return "TRUE"
			else
				state_value[state_index] = false
				return "FALSE"
			end
		end
	end

	redef fun accept_ltl_checker(v, state_id)
	do
		printn "Expression \""
		print_tks
		printn "\" on state {state_id+1} is : \n"
		printn n_simple_expr3.value(v, state_id)
		printn " = "
		printn n_simple_expr4.value(v, state_id)
		printn "\n"
	end

end

redef class Nltlexp_lt

	redef fun value(v, state_index)
	do
		var lvar = n_simple_expr3.value(v, state_index)
		var rvar = n_simple_expr4.value(v, state_index)
		if lvar.to_i < rvar.to_i then
			state_value[state_index] = true
			return "TRUE"
		end
		state_value[state_index] = false
		return "FALSE"
	end
	
	redef fun accept_ltl_checker(v, state_id)
	do
		printn "Expression "
		print_tks
		printn " on state {state_id} is :\n"
		printn n_simple_expr3.value(v, state_id)
		printn " < "
		printn n_simple_expr4.value(v, state_id)
		printn "\n"
	end
end

redef class Nltlexp_gt

	redef fun value(v, state_index)
	do
		var lvar = n_simple_expr3.value(v, state_index)
		var rvar = n_simple_expr4.value(v, state_index)
		if lvar.to_i > rvar.to_i then
			state_value[state_index] = true
			return "TRUE"
		end
		state_value[state_index] = false
		return "FALSE"
	end

	redef fun accept_ltl_checker(v, state_id)
	do
		printn "Expression "
		print_tks
		printn " on state {state_id} is :\n"
		printn n_simple_expr3.value(v, state_id)
		printn " > "
		printn n_simple_expr4.value(v, state_id)
		printn "\n"
	end

end

redef class Nltlexp_ge

	redef fun value(v, state_index)
	do
		var lvar = n_simple_expr3.value(v, state_index)
		var rvar = n_simple_expr4.value(v, state_index)
		if lvar.to_i >= rvar.to_i then
			state_value[state_index] = true
			return "TRUE"
		end
		state_value[state_index] = false
		return "FALSE"
	end

	redef fun accept_ltl_checker(v, state_id)
	do
		printn "Expression "
		print_tks
		printn " on state {state_id} is :\n"
		printn n_simple_expr3.value(v, state_id)
		printn " >= "
		printn n_simple_expr4.value(v, state_id)
		printn "\n"
	end

end

redef class Nltlexp_le

	redef fun value(v, state_index)
	do
		var lvar = n_simple_expr3.value(v, state_index)
		var rvar = n_simple_expr4.value(v, state_index)
		if lvar.to_i <= rvar.to_i then
			state_value[state_index] = true
			return "TRUE"
		end
		state_value[state_index] = false
		return "FALSE"
	end

	redef fun accept_ltl_checker(v, state_id)
	do
		printn "Expression "
		print_tks
		printn " on state {state_id} is : "
		printn n_simple_expr3.value(v, state_id)
		printn " <= "
		printn n_simple_expr4.value(v, state_id)
		printn "\n"
	end

end

redef class Nltlexp_add
	
	redef fun value(v, state_index)
	do
		var lvar = n_simple_expr4.value(v, state_index)
		var rvar = n_simple_expr5.value(v, state_index)
		if not lvar.is_numeric or not rvar.is_numeric then 
			print "Unsupported operation + on something other than Integer"
			abort
		end
		return (lvar.to_i + rvar.to_i).to_s
	end
end

redef class Nltlexp_sub

	redef fun value(v, state_index)
	do
		var lvar = n_simple_expr4.value(v, state_index)
		var rvar = n_simple_expr5.value(v, state_index)
		if not lvar.is_numeric and not rvar.is_numeric then
			print "Unsupported operation / on something other than Integer"
			abort
		end
		return (lvar.to_i - rvar.to_i).to_s
	end

end

redef class Nltlexp_mul

	redef fun value(v, state_index)
	do
		var lvar = n_simple_expr5.value(v, state_index)
		var rvar = n_constant.value(v, state_index)
		if not lvar.is_numeric or not rvar.is_numeric then
			print "Unsupported operation * on something other than Integer"
			abort
		end
		return (lvar.to_i * rvar.to_i).to_s
	end

end

redef class Nltlexp_div

	redef fun value(v, state_index)
	do
		var lvar = n_simple_expr5.value(v, state_index)
		var rvar = n_constant.value(v, state_index)
		if not lvar.is_numeric or not rvar.is_numeric then
			print "Unsupported operation / on something other than Integer"
			abort
		end
		return (lvar.to_i / rvar.to_i).to_s
	end

end

redef class Nltlexp_constant

	redef fun value(v, state_index)
	do
		return n_constant.value(v, state_index)
	end

end

redef class Nenum_block

	fun get_ids(set: Set[String])
	do
		n_elements.get_ids(set)
	end

end

redef class Nelements

	fun get_ids(set: Set[String]) is abstract

end

redef class Nelements_many

	redef fun get_ids(set)
	do
		n_constant.get_ids(set)
		n_elements.get_ids(set)
	end

end

redef class Nelements_one

	redef fun get_ids(set)
	do
		n_constant.get_ids(set)
	end

end

redef class Nconstant

	fun get_ids(set: Set[String]) is abstract

	fun value(v: LTLVisitor, state_index: Int): String is abstract

end

redef class Nconstant_id

	redef fun get_ids(set)
	do
		set.add(n_id.text)
	end

	redef fun value(v, state_id)
	do
		var str = v.states[state_id].get_var(n_id.text) 
		if str == null then return n_id.text
		return str
	end
	
end

redef class Nconstant_int

	redef fun get_ids(set)
	do
		set.add(n_int.text)
	end

	redef fun value(v, state_id) do return n_int.text

end

redef class Nconstant_boolcst

	redef fun get_ids(set)
	do
		set.add(n_bool.text)
	end

	redef fun value(v,i) do return n_bool.text
end

redef class Nconstant_range

	redef fun get_ids(set)
	do
		var lwer = n_int.text.to_i
		var uppr = n_int2.text.to_i
		for i in [lwer..uppr] do set.add(i.to_s)
	end

	redef fun value(v,j) do
		var lwr = n_int.text.to_i
		var uppr = n_int2.text.to_i
		var buf = new Buffer.from("\{")
		for i in [lwr..uppr-1] do
			buf.append i.to_s
			buf.append ","
		end
		buf.append uppr.to_s
		buf.append "\}"
		return buf.to_s
	end

end

redef class HashMap[E, F]

	redef fun [](key: E): F
	do
		if not self.keys.has(key) then print "Error, could not find key {key} in self; will abort"
		return super
	end

end

