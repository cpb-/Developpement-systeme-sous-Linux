#! /usr/bin/python
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

