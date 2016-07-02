#! /usr/bin/python

from __future__ import print_function
import os

ruid = os.getuid()
euid = os.geteuid()
print("R-UID=", ruid, " E-UID=", euid)

os.seteuid(ruid)

ruid = os.getuid()
euid = os.geteuid()
print("R-UID=", ruid, " E-UID=", euid)

os.seteuid(euid)

ruid = os.getuid()
euid = os.geteuid()
print("R-UID=", ruid, " E-UID=", euid)

