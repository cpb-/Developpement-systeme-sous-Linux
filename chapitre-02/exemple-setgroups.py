#! /usr/bin/python

from __future__ import print_function
import os
import sys

if len(sys.argv) == 1:
	print('usage:", sys.argv[0], "GID...")
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

