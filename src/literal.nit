# This file is part of NIT ( http://www.nitlanguage.org ).
#
# Copyright 2012 Jean Privat <jean@pryen.org>
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# Parsing of literal values in the abstract syntax tree.
module literal

import phase

redef class ToolContext
	# Parses literal values in the whole AST and produces errors if needed
	var literal_phase: Phase = new LiteralPhase(self, null)
end

private class LiteralPhase
	super Phase

	redef fun process_nmodule(nmodule) do nmodule.do_literal(toolcontext)
end

redef class AModule
	# Visit the module to compute the real value of the literal-related node of the AST.
	# Warnings and errors are displayed on the toolcontext.
	fun do_literal(toolcontext: ToolContext)
	do
		var v = new LiteralVisitor(toolcontext)
		v.enter_visit(self)
	end
end

private class LiteralVisitor
	super Visitor

	var toolcontext: ToolContext

	redef fun visit(n)
	do
		n.accept_literal(self)
		n.visit_all(self)
	end
end

redef class ANode
	private fun accept_literal(v: LiteralVisitor) do end
end

redef class AExpr
	# Get `self` as a `String`.
	# Return null if not a string.
	fun as_string: nullable String
	do
		if not self isa AStringFormExpr then return null
		return self.value.as(not null)
	end

	# Get `self` as an `Int`.
	# Return null if not an integer.
	fun as_int: nullable Int
	do
		if not self isa AIntegerExpr then return null
		return self.value.as(not null).to_i
	end
end

redef class AIntegerExpr
	# The value of the literal int once computed.
	var value: nullable Numeric

	redef fun accept_literal(v) do
		value = n_integer.text.to_num
		if value == null then
			v.toolcontext.error(hot_location, "Error: invalid literal `{n_integer.text}`")
		end
	end
end

redef class AFloatExpr
	# The value of the literal float once computed.
	var value: nullable Float
	redef fun accept_literal(v)
	do
		self.value = self.n_float.text.to_f
	end
end

# Any kind of entity which supports a prefix or a suffix
class AAugmentedEntity
	# Returns the text of the token
	private fun text: String is abstract

	# Prefix for the entity, "" if no prefix is found
	private fun parse_prefix(del: Char): String do return text.substring(0, text.index_of(del))

	# Suffix for the entity, "" if no prefix is found
	private fun parse_suffix(del: Char): String do return text.substring_from(text.last_index_of(del) + 1)
end

redef class ACharExpr
	super AAugmentedEntity
	# The value of the literal char once computed.
	var value: nullable Char = '\0'

	# Is the expression returning an ASCII byte value ?
	fun is_ascii: Bool do return parse_prefix('\'') == "a"

	# Is the expression returning a Code Point ?
	fun is_code_point: Bool do return parse_prefix('\'') == "u"

	redef fun text do return n_char.text

	redef fun accept_literal(v)
	do
		var prefix = parse_prefix('\'')
		var suffix = parse_suffix('\'')
		var txt = text
		if prefix != "" then txt = txt.substring_from(prefix.length)
		if suffix != "" then txt = txt.substring(0, txt.length - suffix.length)
		txt = txt.unescape_nit
		if txt.length != 3 then
			v.toolcontext.error(self.hot_location, "Syntax Error: invalid character literal `{txt}`.")
			return
		end
		self.value = txt.chars[1]
	end
end

redef class AStringFormExpr
	super AAugmentedEntity
	# The value of the literal string once computed.
	var value: nullable String

	# The underlying bytes of the String, non-cleaned for UTF-8
	var bytes: Bytes is noinit

	# Is `self` a regular String object ?
	fun is_string: Bool do return (fetch_prefix == "" or fetch_prefix == "raw") and fetch_suffix == ""

	# Is `self` a Regular Expression ?
	fun is_re: Bool do return fetch_prefix == "re"

	# Is `self` a Byte String ?
	fun is_bytestring: Bool do return fetch_prefix == "b"

	redef fun text do return n_string.text

	private fun fetch_prefix: String is abstract

	private fun fetch_suffix: String is abstract

	redef fun accept_literal(v)
	do
		var txt = text
		var suffix = fetch_suffix
		var prefix = fetch_prefix
		if prefix != "" then txt = txt.substring_from(prefix.length)
		if suffix != "" then txt = txt.substring(0, txt.length - suffix.length)
		var behead = 1
		var betail = 1
		if txt.chars[0] == txt.chars[1] and txt.length >= 6 then
			behead = 3
			betail = 3
			if txt.chars[0] == '"' and txt.chars[3] == '\n' then behead = 4 # ignore first \n in """
		end
		txt = txt.substring(behead, txt.length - behead - betail)
		if prefix == "raw" then
			bytes = txt.to_bytes
		else
			bytes = txt.unescape_to_bytes
			txt = bytes.to_s
		end
		value = txt
	end
end

redef class AEndStringExpr
	redef fun fetch_prefix do return ""
	redef fun fetch_suffix do return parse_suffix('"')
end

redef class AStartStringExpr
	redef fun fetch_prefix do return parse_prefix('"')
	redef fun fetch_suffix do return ""
end

redef class AMidStringExpr
	redef fun fetch_prefix do return ""
	redef fun fetch_suffix do return ""
end

redef class AStringExpr
	redef fun fetch_prefix do return parse_prefix('"')
	redef fun fetch_suffix do return parse_suffix('"')
end
