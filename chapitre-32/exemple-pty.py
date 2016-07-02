#! /usr/bin/python
from __future__ import print_function
import pty
import os
import select
import socket
import sys
import termios

def connection_handler(newsock):
	try:
		(master_fd, slave_fd) = pty.openpty()
		if os.fork() == 0:
			os.setsid()
			os.close(master_fd)
			termios.tcsetattr(slave_fd, termios.TCSANOW, termios.tcgetattr(0))
			os.dup2(slave_fd, 0)
			os.dup2(slave_fd, 1)
			os.dup2(slave_fd, 2)
			os.execlp("/bin/sh", "/bin/sh")
			sys.exit(1)
	except Exception as e:
		print("Error in child:", str(e))

	os.close(slave_fd)
	while True:
		try:
			(r,w,x) = select.select([master_fd, newsock], [], [])
			if master_fd in r:
				buffer = os.read(master_fd, 4096)
				newsock.send(buffer)
			if newsock in r:
				buffer = newsock.recv(4096)
				os.write(master_fd, buffer)
		except:
			sys.exit(0)


try:
	sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	sock.bind(('', 0))
	(addr, port) = sock.getsockname()
	print("My port number is", port)
	sock.listen(5)
	while True:
		(newsock, addr) = sock.accept()
		if os.fork() == 0:
			connection_handler(newsock)
			sys.exit(0)
		newsock.close()
except Exception as e:
	print("Error in parent:", str(e))


