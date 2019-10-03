#! /usr/bin/python
# ------------------------------------------------------------------
# exemple-setgroups.py
# Fichier d'exemple du livre "Developpement Systeme sous Linux"
# (C) 2015-2019 - Christophe BLAESS <christophe@blaess.fr>
# https://www.blaess.fr/christophe/
# ------------------------------------------------------------------

from __future__ import print_function
import os
import sys

if len(sys.argv) == 1:
	print("usage:", sys.argv[0], "GID...")
else:
	sys.argv.pop(0)
	groups = []
	for arg in sys.argv:
		try:
			groups.append(int(arg))
		except:
			print("Invalid GID:", arg)
			pass
	try:
		os.setgroups(groups)
	except OSError:
		print("Unknown or illegal GID")
		pass

print("Verification:", os.getgroups())

