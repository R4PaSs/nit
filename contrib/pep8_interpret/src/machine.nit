# Basic Pep/8-capable machine
module machine

import c
import console

private fun addressing_map: Map[Int, String] do
	var x = new HashMap[Int, String]
	x[0] = "i"
	x[1] = "d"
	x[2] = "n"
	x[3] = "s"
	x[4] = "sf"
	x[5] = "x"
	x[6] = "sx"
	x[7] = "sxf"
	return once x
end

# Abstraction of a Pep/8 machine with maximum addressable RAM space
#
# Since PEP/8 is a 16 bit machine, the RAM has a 65535 bytes capacity.
class Pep8Machine

	# Is the machine executing a program ?
	var running = false

	# Virtual memory of the machine, all is accessible in read and write
	var ram = new CByteArray(65535)

	# Instruction Pointer
	var ip: UInt16

	# Stack Pointer
	var sp: UInt16

	# Flags (N/Z/V/C)
	#
	# N: Negative
	# Z: Zero
	# V: Overflow
	# C: Carry
	var flags = 0u8

	# Global-Purpose Register A (Accumulator)
	var a: Int16

	# Global-Purpose Register X (Index register)
	var x: Int16

	# Is flag `N` set ?
	fun n: Bool do return (flags & 0b0000_0001u8) != 0u8

	# Sets `N` flag
	fun n=(b: Bool) do if b then flags |= 0b0000_0001u8 else flags &= 0xFFFEu8

	# Is flag `Z` set ?
	fun z: Bool do return flags & 0b0000_0010u8 != 0u8

	# Sets `Z` flag
	fun z=(b: Bool) do if b then flags |= 0b0000_0010u8 else flags &= 0xFFFDu8

	# Is flag `V` set ?
	fun v: Bool do return flags & 0b0000_0100u8 != 0u8

	# Sets `V` flag
	fun v=(b: Bool) do if b then flags |= 0b0000_0100u8 else flags &= 0xFFFBu8

	# Is flag `C` set ?
	fun c: Bool do return flags & 0b0000_1000u8 != 0u8

	# Sets `C` flag
	fun c=(b: Bool) do if b then flags |= 0b0000_1000u8 else flags &= 0xFFF7u8

	# Gets byte at position `i` in `ram`
	fun [](i: UInt16): Byte do return ram[i.to_i]

	# Sets byte at position `i` in `ram`
	fun []=(i: UInt16, b: Byte) do ram[i.to_i] = b

	# Loads a byte sequence into RAM at specified position
	#
	# REQUIRE: `bytes`.length <= 65535 - `pos`
	fun load(bytes: Collection[Byte], pos: UInt16) do
		for i in bytes do
			self[pos] = i
			pos += 1u16
		end
	end

	# Does a full UCT cycle
	fun uct_cycle do
		# Decode instruction
		var exec = decode
		print "Executing {exec}"
		print "---- Cycle ----"
		print " === Regs === ".red
		print "A = {a}".red
		print "X = {x}".red
		print " --- State --- ".green
		print "SP = {sp}".green
		print "IP = {ip}".green
		print " --- Flags --- ".blue
		print "N = {n}".blue
		print "Z = {z}".blue
		print "V = {v}".blue
		print "C = {c}".blue
		print "---- End ----"
		if exec.length == 1 then
			ip += 1u16
		else
			ip += 3u16
		end
		exec.run
	end

	# Run a program at position 0
	fun run do
		running = true
		while running do uct_cycle
	end

	# Decodes the instruction at current IP
	fun decode: Pep8Instruction do
		var instr = self[ip.to_u16]
		if instr & 0b1000_0000u8 == 0u8 then
			if instr & 0b0100_0000u8 == 0u8 then
				if instr &0b0010_0000u8 == 0u8 then
					if instr & 0b0001_0000u8 == 0u8 then
						if instr & 0b0000_1000u8 == 0u8 then
							if instr & 0b0000_0100u8 == 0u8 then
								if instr & 0b0000_0010u8 == 0u8 then
									if instr & 0b0000_0001u8 == 0u8 then
										return new Stop(self)
									else
										return new Rettr(self)
									end
								else
									if instr & 0b0000_0001u8 == 0u8 then
										return new Movspa(self)
									else
										return new Movflga(self)
									end
								end
							else
								if instr & 0b0000_0010u8 == 0u8 then
									return new Br(self)
								else
									return new Brle(self)
								end
							end
						else
							if instr & 0b0000_0100u8 == 0u8 then
								if instr & 0b0000_0010u8 == 0u8 then
									return new Brlt(self)
								else
									return new Breq(self)
								end
							else
								if instr & 0b0000_0010u8 == 0u8 then
									return new Brne(self)
								else
									return new Brge(self)
								end
							end
						end
					else
						if instr & 0b0000_1000u8 == 0u8 then
							if instr & 0b0000_0100u8 == 0u8 then
								if instr & 0b0000_0010u8 == 0u8 then
									return new Brgt(self)
								else
									return new Brv(self)
								end
							else
								if instr & 0b0000_0010u8 == 0u8 then
									return new Brc(self)
								else
									return new Call(self)
								end
							end
						else
							if instr & 0b0000_0100u8 == 0u8 then
								if instr & 0b0000_0010u8 == 0u8 then
									return new Not(self, (instr & 0x01u8).to_i)
								else
									return new Neg(self, (instr & 0x01u8).to_i)
								end
							else
								if instr & 0b0000_0010u8 == 0u8 then
									return new Asl(self, (instr & 0x01u8).to_i)
								else
									return new Asr(self, (instr & 0x01u8).to_i)
								end
							end
						end
					end
				else
					if instr & 0b0001_0000u8 == 0u8 then
						if instr & 0b0000_1000u8 == 0u8 then
							if instr & 0b0000_0010u8 == 0u8 then
								return new Rol(self, (instr & 0x01u8).to_i)
							else
								return new Ror(self, (instr & 0x01u8).to_i)
							end
						else
							return new Nop(self)
						end
					else
						if instr & 0b0000_1000u8 == 0u8 then
							return new Deci(self)
						else
							return new Deco(self)
						end
					end
				end
			else
				if instr & 0b0010_0000u8 == 0u8 then
					if instr & 0b0001_0000u8 == 0u8 then
						if instr & 0b0000_1000u8 == 0u8 then
							return new Stro(self)
						else
							return new Chari(self)
						end
					else
						if instr & 0b0000_1000u8 == 0u8 then
							return new Charo(self)
						else
							return new Retn(self, (instr & 0b0000_0111u8).to_i)
						end
					end
				else
					if instr & 0b0001_0000u8 == 0u8 then
						if instr & 0b0000_1000u8 == 0u8 then
							return new Addsp(self)
						else
							return new Subsp(self)
						end
					else
						return new Add(self, ((instr & 0b0000_1000u8) >> 3).to_i)
					end
				end
			end		
		else
			if instr & 0b0100_0000u8 == 0u8 then
				if instr & 0b0010_0000u8 == 0u8 then
					if instr & 0b0001_0000u8 == 0u8 then
						return new Sub(self, ((instr & 0b0000_1000u8) >> 3).to_i)
					else
						return new And(self, ((instr & 0b0000_1000u8) >> 3).to_i)
					end
				else
					if instr & 0b0001_0000u8 == 0u8 then
						return new Or(self, ((instr & 0b0000_1000u8) >> 3).to_i)
					else
						return new Cp(self, ((instr & 0b0000_1000u8) >> 3).to_i)
					end
				end
			else
				if instr & 0b0010_0000u8 == 0u8 then
					if instr & 0b0001_0000u8 == 0u8 then
						return new Ld(self, ((instr & 0b0000_1000u8) >> 3).to_i)
					else
						return new Ldbyte(self, ((instr & 0b0000_1000u8) >> 3).to_i)
					end
				else
					if instr & 0b0001_0000u8 == 0u8 then
						return new St(self, ((instr & 0b0000_1000u8) >> 3).to_i)
					else
						return new Stbyte(self, ((instr & 0b0000_1000u8) >> 3).to_i)
					end
				end
			end
		end
	end

	# Fetch 16 bits at position `pos` in `ram`
	fun fetch_16(pos: UInt16): Int16 do
		return (self[pos].to_i16 << 8) + self[pos + 1u16].to_i16
	end

	# Sets the 16 bits at position `pos` to the 16 LSB of `pos`
	fun set_16(pos: UInt16, val: Int16) do
		self[pos] = (val >> 8).to_b
		self[pos + 1u16] = val.to_b
	end
end

# Abstract PEP/8 instruction, used to execute something on a VM
class Pep8Instruction
	# Machine the instruction is loaded on
	var m: Pep8Machine

	# Instruction pointer, frozen when created
	var ip: UInt16 = m.ip is lateinit

	# Length of an instruction, corresponds to the increment of IP after execution
	fun length: Int is abstract

	# Executes the instruction on Pep8Machine `m`
	fun run is abstract
end

# Operation taking a register as parameter
class RegisterOp
	super Pep8Instruction

	# Register: 0 for A, 1 for X
	var register: Int

	# Gets the value of the register
	fun regval: Int16 do if register == 0 then return m.a else return m.x

	# Sets the value of the register
	fun regval=(i: Int16) do if register == 0 then m.a = i else m.x = i
end

# An instruction working without operand
class UnaryInstruction
	super Pep8Instruction
	redef fun length do return 1

	redef fun to_s do return "{class_name}"
end

# An instruction working with an operand
class BinaryInstruction
	super Pep8Instruction
	redef fun length do return 3

	# Addressing mode
	#
	# * 0 is `i`
	# * 1 is `d`
	# * 2 is `n`
	# * 3 is `s`
	# * 4 is `sf`
	# * 5 is `x`
	# * 6 is `sx`
	# * 7 is `sxf`
	var addressing: Int is abstract

	# Gets the operand specifier for `self`
	var spec: Int16 is lazy do return (m[ip.to_u16 + 1u16].to_i16 << 8) | m[ip.to_u16 + 2u16].to_i16

	# Operand of the instruction
	var operand: Int16 is writable(set_op), lazy do
		var s = spec.to_u16
		# Immediate => Return directly Spec
		if addressing == 0 then return s.to_i16
		# Direct => Fetch address Spec
		if addressing == 1 then return m.fetch_16(s)
		# Indirect => Mem[Mem[Spec]]
		if addressing == 2 then return m.fetch_16(m.fetch_16(s).to_u16)
		# On the stack => Mem[SP + Spec]
		if addressing == 3 then return m.fetch_16(s + m.sp.to_u16)
		# Stack indirect => Mem[Mem[SP + Spec]]
		if addressing == 4 then return m.fetch_16(m.fetch_16(s + m.sp.to_u16).to_u16)
		# Indexed => Mem[Spec + X]
		if addressing == 5 then return m.fetch_16(s + m.x.to_u16)
		# Stack + indexed => Mem[SP + Spec + X]
		if addressing == 6 then return m.fetch_16(s + m.sp.to_u16 + m.x.to_u16)
		# Sxf => Mem[Mem[Spec + SP] + X]
		if addressing == 7 then return m.fetch_16(m.fetch_16(s + m.sp.to_u16).to_u16 + m.x.to_u16)
		print "Invalid addressing mode {addressing}".red
		m.running = false
		var i = -1i16
		return i.to_i16
	end

	# Sets the 16 bits of Operand to the 16 LSB of `value`
	fun operand_address: UInt16 do
		if addressing == 0 then
			print "Invalid addressing mode `i` for instruction".red
			m.running = false
		end
		if addressing == 1 then return spec.to_u16
		if addressing == 2 then return m.fetch_16(spec.to_u16).to_u16
		if addressing == 3 then return spec.to_u16 + m.sp
		if addressing == 4 then return m.fetch_16(spec.to_u16 + m.sp).to_u16
		if addressing == 5 then return spec.to_u16 + m.x.to_u16
		if addressing == 6 then return spec.to_u16 + m.x.to_u16 + m.sp
		if addressing == 7 then return m.fetch_16(spec.to_u16 + m.sp).to_u16 + m.x.to_u16
		print "Bad addressing mode {addressing}".red
		m.running = false
		var i = 0xFFFFi16
		return i.to_u16
	end

	redef fun to_s do return "{class_name} {spec}, {addressing_map[addressing]} (Operand = {operand})"
end

# Any instruction capable on taking only addressing modes `i` and `x`
class IorX
	super BinaryInstruction

	redef fun addressing do
		if m[ip.to_u16] & 0b0000_0001u8 == 0u8 then return 0
		return 5
	end
end

# Instruction capable of handling any addressing mode
class AnyAddr
	super BinaryInstruction

	redef fun addressing do return (m[ip.to_u16] & 0b0000_0111u8).to_i
end

# Stops the current execution
class Stop
	super UnaryInstruction

	redef fun run do m.running = false
end

# Returns from an interruption
class Rettr
	super UnaryInstruction

	# Unsupported
	redef fun run do abort
end

# Copies the value of SP to A
class Movspa
	super UnaryInstruction

	redef fun run do m.a = m.sp.to_i16
end

# Copies the flags into register A
class Movflga
	super UnaryInstruction

	redef fun run do m.a = m.flags.to_i16 & 0xFFFFi16
end

# Unconditional jump
class Br
	super IorX

	redef fun run do m.ip = operand.to_u16
end

# Jump is lesser or equal (aka if `Z` or `N`)
class Brle
	super IorX

	redef fun run do if m.z or m.n then m.ip = operand.to_u16
end

# Jump if lesser (aka if `N`)
class Brlt
	super IorX

	redef fun run do if m.n then m.ip = operand.to_u16
end

class Breq
	super IorX

	redef fun run do if m.z then m.ip = operand.to_u16
end

class Brne
	super IorX

	redef fun run do if not m.z then m.ip = operand.to_u16
end

class Brge
	super IorX

	redef fun run do if not m.n then m.ip = operand.to_u16
end

class Brgt
	super IorX

	redef fun run do if not m.n and not m.z then m.ip = operand.to_u16
end

class Brv
	super IorX

	redef fun run do if m.v then m.ip = operand.to_u16
end

class Brc
	super IorX

	redef fun run do if m.c then m.ip = operand.to_u16
end

class Call
	super IorX

	redef fun run do
		m.sp -= 2u16
		m.set_16(m.sp, m.ip.to_i16)
		m.ip = operand.to_u16
	end
end

class Not
	super UnaryInstruction
	super RegisterOp

	redef fun run do
		regval = ~regval & 0xFFFFi16
		if regval < 0i16 then m.n = true else m.n = false
		if regval == 0i16 then m.z = true else m.z = false
	end
end

class Neg
	super UnaryInstruction
	super RegisterOp

	redef fun run do
		regval = (-regval) & 0xFFFFi16
		# Shortcut here, the only value that can overflow with NEG is this
		if regval == 0x8000i16 then m.v = true else m.v = false
		if regval < 0i16 then m.n = true else m.n = false
		if regval == 0i16 then m.z = true else m.z = false
	end
end

class Asl
	super UnaryInstruction
	super RegisterOp

	redef fun run do
		var old_msb = regval & 0x8000.to_i16 >> 15
		m.c = old_msb != 0i16
		regval = (regval << 1) & 0xFFFE.to_i16
		var new_msb = regval & 0x8000.to_i16 >> 15
		if old_msb != new_msb then m.v = true else m.v = false
		if regval < 0i16 then m.n = true else m.n = false
		if regval == 0i16 then m.z = true else m.z = false
	end
end

class Asr
	super UnaryInstruction
	super RegisterOp

	redef fun run do
		var old_lsb = (regval & 0x0001i16)
		m.c = old_lsb != 0
		regval = regval >> 1
		if regval < 0i16 then m.n = true else m.n = false
		if regval == 0 then m.z = true else m.z = false
	end
end

class Rol
	super UnaryInstruction
	super RegisterOp

	redef fun run do
		var oldc = if m.c then 1 else 0
		var a = new Asl(m, register)
		a.run
		regval |= oldc.to_i16
		if regval < 0i16 then m.n = true else m.n = false
		if regval == 0i16 then m.z = true else m.z = false
	end
end

class Ror
	super UnaryInstruction
	super RegisterOp

	redef fun run do
		var oldc = if m.c then 1 else 0
		var a = new Asr(m, register)
		a.run
		regval |= oldc.to_i16 << 15
		if regval < 0i16 then m.n = true else m.n = false
		if regval == 0i16 then m.z = true else m.z = false
	end
end

class Nop
	super UnaryInstruction

	redef fun run do end
end

class NopBin
	super BinaryInstruction

	redef fun run do end
end

class Deci
	super AnyAddr

	redef fun run do
		var bf = new FlatBuffer
		var c = getc
		while c.is_numeric do
			bf.add c
			c = getc
		end
		if bf.is_int and not bf.has(".") then
			var out_addr = operand_address
			var val = bf.to_i
			m.set_16(out_addr.to_u16, val.to_i16)
			return
		end
		m.running = false
	end
end

class Deco
	super AnyAddr

	redef fun run do printn operand
end

class Stro
	super AnyAddr

	redef fun run do
		var addressings = once [1, 2, 4]
		if not addressings.has(addressing) then
			m.running = false
			return
		end
		var st_addr = operand_address
		while m[st_addr.to_u16] != 0u8 do
			printn m[st_addr.to_u16].to_i.ascii
			st_addr += 1u16
		end
	end
end

class Chari
	super AnyAddr

	redef fun run do
		var tgt = operand_address
		var rd = stdin.read_byte
		if rd == null then
			m.running = false
			return
		end
		m[tgt.to_u16] = rd.to_b
	end
end

class Charo
	super AnyAddr

	redef fun run do
		printn(operand.to_i.ascii)
	end
end

class Retn
	super UnaryInstruction

	private var retsz: Int

	redef fun run do
		m.sp += retsz.to_u16
		var ret_addr = m.fetch_16(m.sp.to_u16)
		m.ip = ret_addr.to_u16
		m.sp += 2u16
	end
end

class Addsp
	super AnyAddr

	redef fun run do m.sp += operand.to_u16
end

class Subsp
	super AnyAddr

	redef fun run do m.sp -= operand.to_u16
end

class Add
	super AnyAddr
	super RegisterOp

	redef fun run do regval += operand
end

class Sub
	super AnyAddr
	super RegisterOp

	redef fun run do regval -= operand
end

class And
	super AnyAddr
	super RegisterOp

	redef fun run do regval = (regval & operand) & 0xFFFFi16
end

class Or
	super AnyAddr
	super RegisterOp

	redef fun run do regval = (regval | operand) & 0xFFFFi16
end

class Cp
	super AnyAddr
	super RegisterOp

	redef fun run do
		var res = regval - operand
		if res < 0i16 then m.n = true else m.n = false
		if res == 0i16 then m.z = true else m.z = false
	end
end

# Loads a 16-bit value from RAM to Register
class Ld
	super AnyAddr
	super RegisterOp

	redef fun run do
		regval = operand
	end
end

class Ldbyte
	super AnyAddr
	super RegisterOp

	redef fun run do
		regval &= 0xFF00i16
		regval |= (operand & 0xFF00i16) >> 8
	end
end

class St
	super AnyAddr
	super RegisterOp

	redef fun run do
		var st = operand_address
		m.set_16(st.to_u16, regval)
	end
end

class Stbyte
	super AnyAddr
	super RegisterOp

	redef fun run do
		var st = operand_address
		m[st.to_u16] = (regval & 0x00FFi16).to_b
	end
end
