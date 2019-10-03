#! /usr/bin/python
# ------------------------------------------------------------------
# exemple-execvp.py
# Fichier d'exemple du livre "Developpement Systeme sous Linux"
# (C) 2015-2019 - Christophe BLAESS <christophe@blaess.fr>
# https://www.blaess.fr/christophe/
# ------------------------------------------------------------------

from __future__ import print_function
import os

args = [ "ls", "-l", "-n" ]

try:
	os.execvp(args[0], args)
except OSError:
	print("Error, unable to run", args[0])
