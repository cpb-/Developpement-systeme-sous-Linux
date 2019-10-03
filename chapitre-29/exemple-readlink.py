#! /usr/bin/python
# ------------------------------------------------------------------
# exemple-readlink.py
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
		print(f, os.readlink(f))
