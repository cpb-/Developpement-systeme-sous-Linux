#! /usr/bin/python3
import os

nb_cpu = os.sysconf(os.sysconf_names['SC_NPROCESSORS_ONLN'])
while True:
	for i in range(0, nb_cpu):
		cpuset = [i]
		os.sched_setaffinity(0, cpuset)
		for j in range(0,100000000):
			pass

