#! /usr/bin/python
# ------------------------------------------------------------------
# exemple-nice.py
# Fichier d'exemple du livre "Developpement Systeme sous Linux"
# (C) 2015-2019 - Christophe BLAESS <christophe@blaess.fr>
# https://www.blaess.fr/christophe/
# ------------------------------------------------------------------
from __future__ import print_function
import os
import signal
import sys
import time

count = 0;
child = 0
nice = 0

def handler_usr1(signum, stack):
	print("Child {}, nice={:2}, count={}"
	      .format(child, nice, count))


os.setpgid(0, 0)

for child in range(0, 5):
	pid = os.fork()
	if (pid != 0):
		continue
	# Child branch
	signal.signal(signal.SIGUSR1, handler_usr1)
	nice = child * 4
	os.nice(nice)
	signal.pause()
	while True:
		count = count + 1

# Parent branch
signal.signal(signal.SIGUSR1, signal.SIG_IGN)
time.sleep(1)
os.kill(-os.getpgid(0), signal.SIGUSR1)
time.sleep(5)
os.kill(-os.getpgid(0), signal.SIGUSR1)
time.sleep(1)
os.kill(-os.getpgid(0), signal.SIGKILL)

