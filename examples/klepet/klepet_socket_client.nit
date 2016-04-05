# Mini chat program (client-side) made with Nit
#
# Uses sockets to communicate with a Klepet server
module klepet_socket_client

import socket

var port = 4444
var host = "127.0.0.1"

if args.is_empty then
	print "Usage ./minichat_client [host (defaults to 127.0.0.1)]"
else if args.length == 1 then
	host = args[0]
	exit 1
end

var client = new TCPStream.connect(host, port)
if not client.connected then
	print "Unable to connect, is the server up ?"
	exit 1
end
client.blocking = false

print "Connected !"
print "To quit, use command ':Q'"

while client.connected do
	0.05.sleep
	if stdin.ready then
		var msg = gets
		if msg == ":Q" then
			client.close
			break
		end
		if msg == "" then continue
		client.write(msg)
	end
	while client.ready do
		print client.read(100)
	end
end
