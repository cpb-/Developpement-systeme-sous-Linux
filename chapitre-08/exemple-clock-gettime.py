#! /usr/bin/python3

import time

print("CLOCK_REALTIME : ", time.clock_gettime(time.CLOCK_REALTIME))
print("CLOCK_MONOTONIC : ", time.clock_gettime(time.CLOCK_MONOTONIC))
print("CLOCK_MONOTONIC_RAW : ", time.clock_gettime(time.CLOCK_MONOTONIC_RAW))
print("CLOCK_PROCESS_CPUTIME_ID : ", time.clock_gettime(time.CLOCK_PROCESS_CPUTIME_ID))
print("CLOCK_THREAD_CPUTIME_ID : ", time.clock_gettime(time.CLOCK_THREAD_CPUTIME_ID))

