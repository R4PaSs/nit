# Mini chat program (server-side) made with Nit
#
# Uses streams in a uniform way to send/receive data from diverse
# clients, from diverse communication methods.
#
# Right now is supported:
# * Socket
# * Websocket
#
# The program is also a good way to test any kind of new communication stream.
# When a new stream kind is supported, you should add it to Klepet and try if
# some communications are processed correctly.
module klepet_server

import socket
import websocket

var ws_server = new TCPServer(8088)
var server = new TCPServer(4444)
server.blocking = false
ws_server.blocking = false

print "Chat socket server listening on port 4444"
print "Chat websocket server listening on port 8088"

server.listen(5)
ws_server.listen(5)

var clients = new HashSet[CharDuplex]
var marked_for_removal = new HashSet[CharDuplex]

loop
	0.05.sleep
	var webcli = ws_server.accept
	if webcli != null then
		var wscli = new WebsocketConnection(webcli)
		if not wscli.eof then
			clients.add wscli
			print "Websocket client connected !"
		end
	end
	var cli = server.accept
	if cli != null then
		print "Socket client connected !"
		clients.add cli
	end
	if stdin.ready then
		var cmd = gets
		if cmd == "Q" then
			break
		else
			print "Commands:"
			print "Q: Quit"
		end
	end
	for i in clients do
		if i.eof then
			print "Client disconnected !"
			i.close
			marked_for_removal.add i
			continue
		end
		if i.ready then
			var msg = i.read(100)
			if msg == "" then continue
			for j in clients do
				if j == i then continue
				j.write(msg)
			end
		end
	end
	for i in marked_for_removal do
		clients.remove(i)
	end
	marked_for_removal.clear
end
