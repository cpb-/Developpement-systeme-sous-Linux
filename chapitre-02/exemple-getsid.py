#! /usr/bin/python
# ------------------------------------------------------------------
# exemple-getsid.py
# Fichier d'exemple du livre "Developpement Systeme sous Linux"
# (C) 2015-2019 - Christophe BLAESS <christophe@blaess.fr>
# https://www.blaess.fr/christophe/
# ------------------------------------------------------------------

from __future__ import print_function
import os
import sys

if len(sys.argv) == 1:
	print(os.getpid(), ":", os.getsid(0))
else:
	sys.argv.pop(0)
	for pid in sys.argv:
		try:
			print(pid, ":" os.getsid(int(pid)))
		except ValueError:
			print("Invalid PID:", pid)
			pass
		except OSError:
			print("Unknown PID:", pid)
			pass

