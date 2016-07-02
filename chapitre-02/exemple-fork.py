#! /usr/bin/python

from __future__ import print_function
import os

try:
	child_pid = os.fork()
except OSError:
	print("Error in fork()")
	sys.exit(-1)

if (child_pid == 0):
	print("Child:  PID =", os.getpid(),
	      "  PPID =", os.getppid())
else:
	print("Parent: PID =", os.getpid(),
	      "  PPID =", os.getppid(),
	      "  Child =", child_pid)
	os.wait()

