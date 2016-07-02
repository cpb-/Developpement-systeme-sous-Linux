#! /usr/bin/python

from __future__ import print_function
import os

(rgid, egid, sgid) = os.getresgid()
print("R-GID=",rgid," E-GID=",egid," S-GID=",sgid))

os.setresgid(-1, egid, rgid)

(rgid, egid, sgid) = os.getresgid()
print("R-GID=",rgid," E-GID=",egid," S-GID=",sgid))

os.setresgid(-1, sgid, -1)

(rgid, egid, sgid) = os.getresgid()
print("R-GID=",rgid," E-GID=",egid," S-GID=",sgid))

