# This file is part of NIT ( http://www.nitlanguage.org ).
#
# This file is free software, which comes along with NIT. This software is
# distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
# without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
# PARTICULAR PURPOSE. You can modify it is you want, provided this header
# is kept unaltered, and a notification of the changes is added.
# You are allowed to redistribute it and sell it, alone or is a part of
# another product.

# New-style file interaction
module nio_file

intrude import core::file

# Base stream holding a file descriptor
class FileBase
	super Stream 
	# The native file object to read from
	private var file: nullable NativeFile

	# Path to the file
	var path: String

	# File descriptor of this file
	fun fd: Int do return if _file != null then _file.as(not null).fileno else -1

	init do
		var f = _file
		if f != null and f.address_is_null then _file = null
	end

	redef fun close
	do
		var f = _file
		if f == null then return
		if f.address_is_null then
			if last_error != null then return
			last_error = new IOError("Cannot close unopened file")
			return
		end
		var i = f.io_close
		if i != 0 then
			last_error = new IOError("Close failed due to error {sys.errno.strerror}")
		end
		_file = null
	end

	# The status of a file. see POSIX stat(2).
	#
	#     var f = new FileReader.open("/etc/issue")
	#     assert f.file_stat.is_file
	#
	# Return null in case of error
	fun file_stat: nullable FileStat
	do
		var f = _file
		if f == null then return null
		var stat = f.file_stat
		if stat.address_is_null then return null
		return new FileStat(stat)
	end

	# Sets the buffering mode for the current FileStream
	#
	# If the buf_size is <= 0, its value will be 512 by default
	#
	# The mode is any of the buffer_mode enumeration in `Sys`:
	#
	# * `buffer_mode_full`
	# * `buffer_mode_line`
	# * `buffer_mode_none`
	fun set_buffering_mode(buf_size, mode: Int) do
		var f = _file
		if f == null then
			last_error = new IOError("Error, file stream is null")
			return
		end
		if buf_size <= 0 then buf_size = 512
		if f.set_buffering_type(buf_size, mode) != 0 then
			last_error = new IOError("Error while changing buffering type for FileStream, returned error {sys.errno.strerror}")
		end
	end
end

# Byte Reader capable of reading bytes from a file
class FileByteReader
	super ByteReader
	super FileBase

	private var buf = new NativeString(100)

	redef fun read_byte do
		var f = _file
		if f == null then
			last_error = new IOError("Cannot read a byte from a closed file descriptor")
			return null
		end
		var ns = once new NativeString(1)
		var r = f.io_read(ns, 1)
		if r <= 0 then eof = true
		return ns[0]
	end

	redef fun read_bytes(ns, l) do
		var f = _file
		if f == null then
			last_error = new IOError("Cannot read a byte from a closed file descriptor")
			return 0
		end
		var r = f.io_read(ns, l)
		if r <= 0 then eof = true
		return r
	end

	redef var eof = false

	redef fun append_all_bytes(b) do
		var f = _file
		if f == null then
			last_error = new IOError("Cannot read a byte from a closed file descriptor")
			return 0
		end
		var bf = buf 
		var r = f.io_read(bf, 100)
		var rd = r
		while r > 0 do
			b.append_ns(bf, r)
			r = f.io_read(bf, 100)
			rd += r
		end
		eof = true
		return rd
	end

	redef fun ready(t) do return not eof
end

# Byte Reader capable of reading bytes from a file
class FileByteWriter
	super ByteWriter
	super FileBase

	# Internal buffer used to write bytes
	private var buf = new NativeString(1)

	redef fun write_byte(b) do
		var f = _file
		if f == null then
			last_error = new IOError("Cannot write a byte to a closed file descriptor")
			return
		end
		buf[0] = b
		f.io_write(buf, 0, 1)
	end

	redef fun write_bytes(ns, ln) do
		var f = _file
		if f == null then
			last_error = new IOError("Cannot write a byte to a closed file descriptor")
			return
		end
		f.io_write(ns, 0, ln)
	end
end

# New-style file reader
class NioFileReader
	super Reader

	# Opens a file `file`
	#
	# If it does not exist, creates it
	init open(path: String) do
		var fl = new NativeFile.io_open_read(path.to_cstring)
		if fl.address_is_null then
			last_error = new IOError("Cannot open `{path}`: {sys.errno.strerror}")
		end
		init(new CharReader(new FileByteReader(fl, path)))
	end

	# Creates a new File stream from a file descriptor
	#
	# This is a low-level method.
	init from_fd(fd: Int) do
		var fl = fd.fd_to_stream(read_only)
		if fl.address_is_null then
			last_error = new IOError("Error: Converting fd {fd} to stream failed with '{sys.errno.strerror}'")
		end
		init(new CharReader(new FileByteReader(fl, "")))
	end

	redef fun eof do return src.eof
end

# Writer to a file
class NioFileWriter
	super Writer

	# Open the file at `path` for writing.
	init open(path: String)
	do
		var fl = new NativeFile.io_open_write(path.to_cstring)
		if fl.address_is_null then
			last_error = new IOError("Cannot open `{path}`: {sys.errno.strerror}")
		end
		init(new CharWriter(new FileByteWriter(fl, path)))
	end

	# Creates a new File stream from a file descriptor
	init from_fd(fd: Int) do
		var fl = fd.fd_to_stream(wipe_write)
		if fl.address_is_null then
			 last_error = new IOError("Error: Opening stream from file descriptor {fd} failed with '{sys.errno.strerror}'")
		end
		init(new CharWriter(new FileByteWriter(fl, "")))
	end
end
