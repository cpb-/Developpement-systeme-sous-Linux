#! /usr/bin/python
# ------------------------------------------------------------------
# exemple-buffers.py
# Fichier d'exemple du livre "Developpement Systeme sous Linux"
# (C) 2015-2019 - Christophe BLAESS <christophe@blaess.fr>
# https://www.blaess.fr/christophe/
# ------------------------------------------------------------------
from __future__ import print_function
import sys

print("1 stdout : ligne + \\n")
print("2 stdout : ligne seule", end='')
print("\n3 stderr : avant flush()", file=sys.stderr)
sys.stdout.flush()
print("\n4 stderr : apres flush ()", file=sys.stderr)
print("5 stdout : ligne seule ", end='')
print("\n6 stderr : avant sys.stdin.read()", file=sys.stderr)
sys.stdin.readline()
print("\n7 stderr : apres sys.stdin.read(stdin)", file=sys.stderr)

