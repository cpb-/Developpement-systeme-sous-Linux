#! /usr/bin/python

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

