#! /usr/bin/python
# ------------------------------------------------------------------
# exemple-argparse-1.py
# Fichier d'exemple du livre "Developpement Systeme sous Linux"
# (C) 2015-2019 - Christophe BLAESS <christophe@blaess.fr>
# https://www.blaess.fr/christophe/
# ------------------------------------------------------------------

from __future__ import print_function
import argparse
import sys

parser = argparse.ArgumentParser()
parser.add_argument('-a', action='store_true')
parser.add_argument('-b', action='store_true')
parser.add_argument('-c', )
parser.add_argument('-X', action='store_true')
parser.add_argument('-Y', action='store_true')
args = parser.parse_args()

print(vars(args))
