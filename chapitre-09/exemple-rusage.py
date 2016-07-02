#! /usr/bin/python
from __future__ import print_function
import os
import resource
import sys
import time

if len(sys.argv) == 1:
	who = resource.RUSAGE_SELF
else:
	os.system(sys.argv[1])
	who = resource.RUSAGE_CHILDREN

ru = resource.getrusage(who)
print("User CPU time      =", ru.ru_utime)
print("System CPU time    =", ru.ru_stime)
print("Maximal RSS (kb)   =", ru.ru_maxrss)
print("Volontary switches =", ru.ru_nvcsw)
print("Preemptions        =", ru.ru_nivcsw)


