import machine

if args.is_empty then
	print "Usage: ./interpret cuillere.pepo"
	exit -1
end

var fl = new FileReader.open(args[0])
var program = new Array[Byte]
for i in fl.each_line do
	for j in i.split(" ") do program.push j.to_hex.to_b
end

print program

var m = new Pep8Machine(0u16, 0xFFFFu16, 0i16, 0i16)
m.load(program, 0u16)
m.run
