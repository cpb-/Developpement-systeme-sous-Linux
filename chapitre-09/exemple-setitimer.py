#! /usr/bin/python
from __future__ import print_function
import signal
import sys
import time

def handler_sigalrm(signum, stack):
	print("Alarme !", file=sys.stderr)

signal.signal(signal.SIGALRM, handler_sigalrm)
signal.setitimer(signal.ITIMER_REAL, 5, 5)
while True:
	print(".", file=sys.stderr, end='')
	time.sleep(1)

