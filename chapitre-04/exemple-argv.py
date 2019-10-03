#! /usr/bin/python
# ------------------------------------------------------------------
# exemple-argv.py
# Fichier d'exemple du livre "Developpement Systeme sous Linux"
# (C) 2015-2019 - Christophe BLAESS <christophe@blaess.fr>
# https://www.blaess.fr/christophe/
# ------------------------------------------------------------------

from __future__ import print_function
import sys

print(sys.argv[0], "a recu en argument :")
sys.argv.pop(0)
for var in sys.argv:
	print(" ", var)
