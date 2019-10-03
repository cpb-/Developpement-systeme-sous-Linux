#! /usr/bin/python
# ------------------------------------------------------------------
# exemple-localtime.py
# Fichier d'exemple du livre "Developpement Systeme sous Linux"
# (C) 2015-2019 - Christophe BLAESS <christophe@blaess.fr>
# https://www.blaess.fr/christophe/
# ------------------------------------------------------------------

from __future__ import print_function
import time

t = time.time()

print("time.time()      =", t)

tm = time.localtime(t)
if (tm.tm_isdst > 0):
	dst = "Ete"
elif (tm.tm_isdst == 0):
	dst = "Normal"
else:
	dst = "?"
print("time.localtime() = {:02}/{:02}/{:02} {:02}:{:02}:{:02} {}".format(
       tm.tm_mday, tm.tm_mon, tm.tm_year % 100,
       tm.tm_hour, tm.tm_min, tm.tm_sec, dst))

tm = time.gmtime(t)
if (tm.tm_isdst > 0):
	dst = "Ete"
elif (tm.tm_isdst == 0):
	dst = "Normal"
else:
	dst = "?"
print("time.gmtime()    = {:02}/{:02}/{:02} {:02}:{:02}:{:02} {}".format(
       tm.tm_mday, tm.tm_mon, tm.tm_year % 100,
       tm.tm_hour, tm.tm_min, tm.tm_sec, dst))
