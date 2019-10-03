#! /usr/bin/python
# ------------------------------------------------------------------
# exemple-execve.py
# Fichier d'exemple du livre "Developpement Systeme sous Linux"
# (C) 2015-2019 - Christophe BLAESS <christophe@blaess.fr>
# https://www.blaess.fr/christophe/
# ------------------------------------------------------------------

from __future__ import print_function
import os

arg = [ 'bash', '-c', 'echo $SHLVL' ]

print("Running: /bin/bash -c 'echo $SHLVL'");
try:
	os.execve('/bin/bash', arg, os.environ)
except OSError:
	print("Failed")


