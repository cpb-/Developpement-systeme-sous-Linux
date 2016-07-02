#! /usr/bin/python
from __future__ import print_function
import os
import fcntl
import select
import sys
import time

read_list = []

for i in range (0, 9):
	(fd_r, fd_w) = os.pipe()
	if os.fork() != 0:
		os.close(fd_r)
		while True:
			time.sleep(i+1)
			os.write(fd_w, chr(48+i))
	else:
		read_list.append(fd_r)

while True:
	(r, w, x) = select.select(read_list, [], [])
	for fd in r:
		c = os.read(fd, 4096)
		print(c, end=' ', file=sys.stderr)
