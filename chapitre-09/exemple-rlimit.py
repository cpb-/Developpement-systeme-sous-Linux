#! /usr/bin/python
# ------------------------------------------------------------------
# exemple-rlimit.py
# Fichier d'exemple du livre "Developpement Systeme sous Linux"
# (C) 2015-2019 - Christophe BLAESS <christophe@blaess.fr>
# https://www.blaess.fr/christophe/
# ------------------------------------------------------------------
from __future__ import print_function
import resource

(soft, hard) = resource.getrlimit(resource.RLIMIT_NPROC)
print("Nb processes:", soft, "/", hard)
(soft, hard) = resource.getrlimit(resource.RLIMIT_NOFILE)
print("Nb files:", soft, "/", hard)
(soft, hard) = resource.getrlimit(resource.RLIMIT_DATA)
print("Data size:", soft, "/", hard)
(soft, hard) = resource.getrlimit(resource.RLIMIT_STACK)
print("Stack :", soft, "/", hard)

