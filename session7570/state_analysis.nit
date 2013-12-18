# Parses and analyses the States and their variable in a NuSMV XML Trace file

import xml_lexer
import xml_parser

class State

	var id: String
	private var variables = new HashMap[String, String]
	var next: nullable State = null
	var previous: nullable State = null

	fun get_var(name: String): nullable String
	do
		if variables.keys.has(name) then return variables[name]
		if previous != null then return previous.get_var(name)
		return null
	end

end

class XMLTraceAnalyser

	var states: Sequence[State]

	init(target: String)
	do
		var read = new IFStream.open(target).read_all
		var lex = new Lexer_xml(read)
		var tks = lex.lex
		var parser = new Parser_xml
		parser.tokens.add_all(tks)
		var top_node = parser.parse
		var visit = new XMLTraceVisitor
		visit.enter_visit(top_node)
		states = visit.states
		var curr_state: nullable State = null
		for i in states do
			if curr_state != null then
				i.previous = curr_state
				curr_state.next = i
			end
		end
	end

end

class XMLTraceVisitor
	super Visitor

	var states = new List[State]

	var curr_state: nullable State = null

	redef fun visit(n) do n.accept_xml_trace_visitor(self)

end

redef class Node

	fun accept_xml_trace_visitor(v: XMLTraceVisitor) do visit_children(v)

end

redef class Nstate

	redef fun accept_xml_trace_visitor(v)
	do
		var state_id = n_string.text
		v.curr_state = new State(state_id.substring(1, state_id.length-2))
		v.states.push(v.curr_state.as(not null))
		visit_children(v)
	end

end

redef class Nvalue

	redef fun accept_xml_trace_visitor(v)
	do
		var var_name = n_string.text
		var_name = var_name.substring(1, var_name.length-2)
		var val = n_valdata.text
		v.curr_state.variables[var_name] = val
	end

end


