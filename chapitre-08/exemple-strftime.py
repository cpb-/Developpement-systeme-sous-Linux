#! /usr/bin/python
# ------------------------------------------------------------------
# exemple-strftime.py
# Fichier d'exemple du livre "Developpement Systeme sous Linux"
# (C) 2015-2019 - Christophe BLAESS <christophe@blaess.fr>
# https://www.blaess.fr/christophe/
# ------------------------------------------------------------------

from __future__ import print_function
import locale
import sys
import time

locale.setlocale(locale.LC_ALL,'')
sys.argv.pop(0)
for arg in sys.argv:
	print(time.strftime(arg))

