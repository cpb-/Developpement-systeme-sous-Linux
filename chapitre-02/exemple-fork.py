#! /usr/bin/python
# ------------------------------------------------------------------
# exemple-fork.py
# Fichier d'exemple du livre "Developpement Systeme sous Linux"
# (C) 2015-2019 - Christophe BLAESS <christophe@blaess.fr>
# https://www.blaess.fr/christophe/
# ------------------------------------------------------------------


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

