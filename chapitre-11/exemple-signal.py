#! /usr/bin/python

from __future__ import print_function
import signal
import os

def handler(num, stack):
	print("Signal", num, "recu")

for sig in range(1, signal.NSIG):
	try:
		signal.signal(sig, handler)
	except:
		print("Unable to catch signal", sig)

while True:
	signal.pause()
