#! /usr/bin/python
from __future__ import print_function
import os

(fd_r, fd_w) = os.pipe()

if os.fork() == 0:
	print("Child process: closing the pipe input")
	os.close(fd_w)
	print("Child process: reading from the pipe")
	r = os.read(fd_r, 4096)
	print("Child process got:", r);
else:
	print("Parent process: closing the pipe output")
	os.close(fd_r)
	print("Parent process: writing into the pipe")
	os.write(fd_w, "Hello from the your parent!")
	os.wait()

