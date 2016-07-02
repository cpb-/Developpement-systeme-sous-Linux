#! /usr/bin/python3
import os
import sys

sys.argv.pop(0)
for arg in sys.argv:
	try:
		sched = os.sched_getscheduler(int(arg))
		if sched == os.SCHED_RR:
			print(arg, "RR")
		elif sched == os.SCHED_FIFO:
			print(arg, "FIFO")
		else:
			print(arg, "OTHER")
	except ValueError:
		print("Invalid PID", arg)
	except OSError:
		print("Unknown PID", arg)

