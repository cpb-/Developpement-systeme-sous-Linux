#! /usr/bin/python
from __future__ import print_function
import time

time.tzset()
(nodst, dst) = time.tzname
print("no DST =", nodst)
print("   DST =", dst)
