#! /usr/bin/python3
# ------------------------------------------------------------------
# exemple-get-priority-min-max.py
# Fichier d'exemple du livre "Developpement Systeme sous Linux"
# (C) 2015-2019 - Christophe BLAESS <christophe@blaess.fr>
# https://www.blaess.fr/christophe/
# ------------------------------------------------------------------
import os

print ("FIFO : {} <= prio <= {}".format(
       os.sched_get_priority_min(os.SCHED_FIFO),
       os.sched_get_priority_max(os.SCHED_FIFO)))
print ("RR   : {} <= prio <= {}".format(
       os.sched_get_priority_min(os.SCHED_RR),
       os.sched_get_priority_max(os.SCHED_RR)))
print ("OTHER: {} <= prio <= {}".format(
       os.sched_get_priority_min(os.SCHED_OTHER),
       os.sched_get_priority_max(os.SCHED_OTHER)))

