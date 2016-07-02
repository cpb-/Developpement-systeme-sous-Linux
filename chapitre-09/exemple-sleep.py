#! /usr/bin/python
from __future__ import print_function
import os
import signal
import time

def handler_usr1(signum, stack):
	pass

signal.signal(signal.SIGUSR1, handler_usr1)
pid = os.fork()
if (pid == 0):
	print("Before :", time.ctime())
	time.sleep(10)
	print("After  :", time.ctime())
else:
	time.sleep(2)
	os.kill(pid, signal.SIGUSR1)

