#! /usr/bin/python3
import os
import signal

try:
	os.sched_setscheduler(0, os.SCHED_FIFO, os.sched_param(99))
	signal.alarm(20)
	while True:
		pass
except PermissionError:
	print("You need root permission to run as realtime process")


