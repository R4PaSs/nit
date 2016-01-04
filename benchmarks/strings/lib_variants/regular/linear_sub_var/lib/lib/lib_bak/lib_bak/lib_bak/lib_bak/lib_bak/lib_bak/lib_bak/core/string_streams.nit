# This file is part of NIT ( http://www.nitlanguage.org ).
#
# This file is free software, which comes along with NIT. This software is
# distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
# without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
# PARTICULAR PURPOSE. You can modify it is you want, provided this header
# is kept unaltered, and a notification of the changes is added.
# You are allowed to redistribute it and sell it, alone or is a part of
# another product.

# Streams capable of writing to Strings
module string_streams

import stream

redef class Writable
	# Like `write_to` but return a new String (may be quite large)
	#
	# This funtionality is anectodical, since the point
	# of streamable object to be efficienlty written to a
	# stream without having to allocate and concatenate strings
	fun write_to_string: String
	do
		var stream = new StringWriter
		write_to(stream)
		return stream.to_s
	end
end

# Stream to write bytes in memory
class InMemoryWriter
	super ByteWriter

	# Where the bytes will be written
	var src = new Bytes.empty

	redef fun write_byte(b) do src.add b

	redef fun write_bytes(ns, ln) do src.append_ns(ns, ln)

	redef fun is_writable do return true
end

# Stream to write bytes in memory
class InMemoryReader
	super ByteReader

	# Where the bytes will be written
	var src: SequenceRead[Byte]

	# Position in source
	private var pos = 0

	redef fun ready(timeout) do return eof

	redef fun eof do return pos < src.length

	redef fun read_byte do
		if pos < src.length then
			var b = src[pos]
			pos += 1
			return b
		end
		return null
	end
end

# `Stream` that can be used to write to a `String`
#
# Mainly used for compatibility with Writer type and tests.
class StringWriter
	super Writer
	noautoinit

	private var buf: Bytes
	
	init do
		var b = new InMemoryWriter
		buf = b.src
		writer = new CharWriter(b)
	end

	redef fun is_writable do return true

	# Is the stream closed?
	protected var closed = false

	redef fun close do closed = true
end

# `Stream` used to read from a `String`
#
# Mainly used for compatibility with Reader type and tests.
class StringReader
	super Reader
	noautoinit

	# Standard constructor with a `Text` object as only parameter
	init(s: Text) is old_style_init do
		var rd = new InMemoryReader(s.bytes)
		super(new CharReader(rd))
	end
end
