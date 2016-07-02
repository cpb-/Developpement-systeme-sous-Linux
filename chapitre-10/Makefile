SHELL=/bin/sh

CFLAGS = -Wall -g -pthread
LDFLAGS = -lrt -pthread

EXECUTABLES=                                 \
		exemple-status               \
		exemple-nice                 \
		exemple-getpriority          \
		exemple-sched-getcpu         \
		exemple-pthread-setaffinity  \
		exemple-get-priority-min-max \
		exemple-getscheduler         \
		exemple-boucle-temps-reel    \
		exemple-ordonnancement       \




all : ${EXECUTABLES}

clean : 
	@rm -f core *.o a.out *~
	@rm -f ${EXECUTABLES}
