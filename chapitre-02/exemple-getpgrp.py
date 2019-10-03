#! /usr/bin/python
# ------------------------------------------------------------------
# exemple-getpgrp.py
# Fichier d'exemple du livre "Developpement Systeme sous Linux"
# (C) 2015-2019 - Christophe BLAESS <christophe@blaess.fr>
# https://www.blaess.fr/christophe/
# ------------------------------------------------------------------

from __future__ import print_function
import os

print(os.getpid(), ":", os.getpgrp())
