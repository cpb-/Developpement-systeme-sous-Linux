#! /usr/bin/python

from __future__ import print_function
import os
import time

if (os.fork() != 0):
	print("[PARENT] My PID is", os.getpid())
	time.sleep(2)
	print("[PARENT] Terminating now!")

else:
	for i in range(1,5):
		print("[CHILD] My parent is", os.getppid())
		time.sleep(1)

