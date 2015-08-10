
import console

if args.is_empty then
	print "Usage: ./asem8all directory"
	exit 1
end

var path_str = args[0]

var path = path_str.to_path

if not path.exists then
	print "Error: path `{args[0]}` is invalid"
	exit 2
end

if not path.stat.is_dir then 
	print "Error, `{args[0]}` is not a directory".red
	exit 3
end

print "Assembling programs of directory {args[0]}"
for i in path.files do
	print "Assembling {i}"
	var p = new ProcessReader("./asem8", i.to_s)
	p.wait
	var s = p.stream_in
	print "Command returned {p.status}, messages = {s.read_all}"
end
print "Done assembling programs"
