#! /usr/bin/python
# ------------------------------------------------------------------
# exemple-setresuid.py
# Fichier d'exemple du livre "Developpement Systeme sous Linux"
# (C) 2015-2019 - Christophe BLAESS <christophe@blaess.fr>
# https://www.blaess.fr/christophe/
# ------------------------------------------------------------------

from __future__ import print_function
import os

(ruid, euid, suid) = os.getresuid()
print("R-UID=",ruid," E-UID=",euid," S-UID=",suid)

os.setresuid(-1, euid, ruid)

(ruid, euid, suid) = os.getresuid()
print("R-UID=",ruid," E-UID=",euid," S-UID=",suid)

os.setresuid(-1, suid, -1)

(ruid, euid, suid) = os.getresuid()
print("R-UID=",ruid," E-UID=",euid," S-UID=",suid)

