#! /usr/bin/python
# ------------------------------------------------------------------
# exemple-glob.py
# Fichier d'exemple du livre "Developpement Systeme sous Linux"
# (C) 2015-2019 - Christophe BLAESS <christophe@blaess.fr>
# https://www.blaess.fr/christophe/
# ------------------------------------------------------------------

from __future__ import print_function
import glob
import sys

for f in glob.glob(sys.argv[1]):
	print(f)
