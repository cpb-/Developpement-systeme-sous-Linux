#! /usr/bin/python
# ------------------------------------------------------------------
# exemple-setreuid.py
# Fichier d'exemple du livre "Developpement Systeme sous Linux"
# (C) 2015-2019 - Christophe BLAESS <christophe@blaess.fr>
# https://www.blaess.fr/christophe/
# ------------------------------------------------------------------

from __future__ import print_function
import os

ruid = os.getuid()
euid = os.geteuid()
print("R-UID=", ruid, " E-UID=", euid)

os.setreuid(-1, ruid)

ruid = os.getuid()
euid = os.geteuid()
print("R-UID=", ruid, " E-UID=", euid)

os.setreuid(-1, euid)

ruid = os.getuid()
euid = os.geteuid()
print("R-UID=", ruid, " E-UID=", euid)

os.setreuid(euid, -1)

ruid = os.getuid()
euid = os.geteuid()
print("R-UID=", ruid, " E-UID=", euid)

