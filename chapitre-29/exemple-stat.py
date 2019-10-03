#! /usr/bin/python
# ------------------------------------------------------------------
# exemple-stat.py
# Fichier d'exemple du livre "Developpement Systeme sous Linux"
# (C) 2015-2019 - Christophe BLAESS <christophe@blaess.fr>
# https://www.blaess.fr/christophe/
# ------------------------------------------------------------------

from __future__ import print_function
import os
import stat
import sys

sys.argv.pop(0)
for f in sys.argv:
	try:
		s = os.stat(f)
		if (stat.S_ISBLK(s.st_mode)):
			print(f, "bloc")
		if (stat.S_ISCHR(s.st_mode)):
			print(f, "caractere")
		if (stat.S_ISDIR(s.st_mode)):
			print(f, "repertoire")
		if (stat.S_ISFIFO(s.st_mode)):
			print(f, "fifo")
		if (stat.S_ISLNK(s.st_mode)):
			print(f, "lien")
		if (stat.S_ISREG(s.st_mode)):
			print(f, "fichier")
		if (stat.S_ISSOCK(s.st_mode)):
			print(f, "socket")
	except:
		print(f, "erreur")
