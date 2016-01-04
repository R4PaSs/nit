# This file is part of NIT ( http://www.nitlanguage.org ).
#
# This file is free software, which comes along with NIT. This software is
# distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
# without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
# PARTICULAR PURPOSE. You can modify it is you want, provided this header
# is kept unaltered, and a notification of the changes is added.
# You are allowed to redistribute it and sell it, alone or is a part of
# another product.

# Base architecture for new I/O classes
module io_base

intrude import core::text::flat
import core::stream
intrude import core::bytes
import core::codecs

# Any kind of stream is `IO`
class IO
	# Has an error been encountered ?
	var last_error: nullable IOError = null

	# Close the stream
	fun close is abstract
end

# Stream that supports reading bytes from a source
class ByteReader
	super IO

	# Has the stream reached the end ?
	fun eof: Bool is abstract

	# Is the source ready to be read without blocking ?
	#
	# If timeout is left to `null`, function will return immediately
	fun ready(timeout: nullable Int): Bool is abstract

	# Read a byte from source input
	fun read_byte: nullable Byte is abstract

	# Reads up to `max` bytes from source and stores them in `bytes`
	fun read_bytes(bytes: NativeString, max: Int): Int do
		var rd = 0
		while rd < max do
			var b = read_byte
			if b == null then break
			bytes[rd] = b
		end
		return rd
	end

	# Reads all the content from the source until `eof` is reached
	#
	# WARNING: This can hang-up if done on a non-finishable source
	# Take extra care when using this method.
	fun read_all_bytes: Bytes do
		var b = new Bytes.with_capacity(100)
		append_all_bytes(b)
		return b
	end

	# Appends all the next bytes from source to `b`
	#
	# WARNING: This can hang-up if done on a non-finishable source
	# Take extra care when using this method. 
	protected fun append_all_bytes(b: Bytes): Int do
		var bf = new NativeString(100)
		var rd = 0
		while not eof do
			rd += read_bytes(bf, 100)
			b.append_ns(bf, rd)
		end
		return rd
	end
end

# Base interface for streams capable of reading chars
class ICharReader
	super ByteReader
	# Reads a char from input source
	#
	# Returns unicode replacement character '�' if an
	# invalid byte sequence is read.
	fun read_char: nullable Char is abstract

	# Read a line from Stream
	fun read_line: String is abstract

	# Reads all the content of a stream
	fun read_all: String is abstract

	# Change decoder for `self`
	fun decoder=(d: Decoder) is abstract
end

# Stream capable of reading chars from a source
class CharReader
	super ICharReader

	# Source to read bytes from
	var src: ByteReader

	private var decoder: Decoder = utf8_decoder is private writable(set_decoder)

	# Changes the decoder for the current stream (how characters will be read)
	redef fun decoder=(d) do
		set_decoder(d)
		lookahead = new NativeString(decoder.max_lookahead)
	end

	redef fun ready(t) do return src.ready(t)

	redef fun eof do return lookahead_length == 0 and src.eof

	# Lookahead for the next char to read
	private var lookahead = new NativeString(decoder.max_lookahead) is lateinit

	# Capacity of the lookahead
	private var lookahead_capacity: Int = utf8_decoder.max_lookahead is lateinit

	# Length currently occupied in the lookahead
	private var lookahead_length: Int = 0

	redef fun close do src.close

	redef fun read_byte do
		if lookahead_length > 0 then
			var b = lookahead[0]
			lookahead.lshift(1, lookahead_length - 1, 1)
			return b
		end
		return src.read_byte
	end

	redef fun read_bytes(bytes, max) do
		var rd = 0
		if lookahead_length > 0 then
			rd = lookahead_length
			lookahead.copy_to(bytes, lookahead_length, 0, 0)
			lookahead_length = 0
		end
		if src.ready then rd += read_bytes(bytes.fast_cstring(rd), max - rd)
		return rd
	end

	redef fun append_all_bytes(b) do
		var rd = lookahead_length
		if rd > 0 then
			b.append_ns(lookahead, rd)
			lookahead_length = 0
		end
		rd += src.append_all_bytes(b)
		return rd
	end

	redef fun read_char do
		var ln = lookahead_length
		var l = lookahead
		var codet_sz = decoder.codet_size
		if ln == 0 then
			var b = src.read_bytes(l, codet_sz)
			if b < codet_sz then return null
			ln = codet_sz
		end
		var cap = lookahead_capacity
		var ret = decoder.is_valid_char(l, ln)
		while ret == 1 and ln < cap do
			if not src.ready then
				l.lshift(codet_sz, ln - codet_sz, codet_sz)
				return '�'
			end
			var b = src.read_bytes(l.fast_cstring(ln), codet_sz)
			if b < codet_sz then
				l.lshift(codet_sz, ln - codet_sz, codet_sz)
				return '�'
			end
			ln += codet_sz
			ret = decoder.is_valid_char(l, ln)
		end
		if ret == 0 then
			var c = decoder.decode_char(l)
			lookahead_length = 0
			return c
		end
		if ret == 2 or ret == 1 then
			l.lshift(codet_sz, ln - codet_sz, codet_sz)
			lookahead_length = ln - codet_sz
			return '�'
		end
		# Should not happen if the decoder works properly
		var arr = new Array[Object]
		arr.push "Decoder error: could not decode nor recover from byte sequence ["
		for i in [0 .. ln[ do
			arr.push l[i]
			arr.push ", "
		end
		arr.push "]"
		last_error = new IOError(arr.to_s)
		return '�'
	end

	redef fun read_line do
		var s = new Bytes.empty
		var b = src.read_byte
		while b != null do
			s.add b
			if b == 0x0Au8 then break
			b = src.read_byte
		end
		return s.to_s.chomp
	end

	redef fun read_all do
		var b = new Bytes.empty
		append_all_bytes(b)
		return decoder.decode_string(b.items, b.length)
	end
end

# Reader capable of reading bytes or chars from a source
class NioReader
	super ICharReader

	redef fun decoder=(d) do src.decoder = d

	# The char source, bound on the byte source
	protected var src: CharReader

	redef fun ready(t) do return src.ready

	redef fun read_byte do return src.read_byte

	redef fun read_bytes(ns, max) do return src.read_bytes(ns, max)

	redef fun read_char do return src.read_char

	redef fun read_line do return src.read_line

	redef fun read_all do return src.read_all
end

# Writer capable of writing bytes to a destination
class ByteWriter
	super IO

	# Write a byte to destination
	fun write_byte(b: Byte) is abstract

	# Write `ln` bytes from `ns` to a destination
	fun write_bytes(ns: NativeString, ln: Int) do
		for i in [0 .. ln[ do write_byte(ns[i])
	end
end

# Base interface for streams capable of reading chars
class ICharWriter
	super ByteWriter

	# Writes a char to destination
	fun write_char(c: Char) is abstract

	# Writes a whole `text` to destination
	fun write(s: Text) do for i in s.chars do write_char i

	# Change coder for `self`
	fun coder=(c: Coder) is abstract
end

# Writes chars to a destination
class CharWriter
	super ICharWriter

	# Source stream writing bytes
	var src: ByteWriter

	private var coder: Coder = utf8_coder is private writable(set_coder)

	private var char_buffer = new NativeString(coder.char_max_size) is lateinit

	redef fun coder=(c) do
		set_coder(c)
		char_buffer = new NativeString(coder.char_max_size)
	end

	redef fun write_char(c) do
		var sz = coder.add_char_to(c, char_buffer)
		src.write_bytes(char_buffer, sz)
	end

	redef fun write(s) do
		var b = new Bytes.with_capacity(s.bytelen)
		coder.add_string_to(s, b)
		src.write_bytes(b.items, b.length)
	end

	# Write a byte to destination
	redef fun write_byte(b) do src.write_byte b

	# Write `ln` bytes from `ns` to a destination
	redef fun write_bytes(ns, ln) do src.write_bytes(ns, ln)
end

# Stream capable of writing bytes or chars to a destination
class NioWriter
	super ICharWriter

	# Writer class to use as destination stream
	var src: CharWriter

	redef fun write_char(c) do src.write_char c

	redef fun write(s) do src.write s

	redef fun coder=(c) do src.set_coder(c)

	redef fun write_byte(b) do src.write_byte b

	redef fun write_bytes(ns, ln) do src.write_bytes(ns, ln)
end
