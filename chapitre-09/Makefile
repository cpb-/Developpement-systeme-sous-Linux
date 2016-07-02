SHELL=/bin/sh

CFLAGS = -Wall -g 
LDFLAGS = -lrt
LOADLIBES=-lrt

EXECUTABLES=                                 \
		exemple-sleep                \
		exemple-usleep-1             \
		exemple-usleep-2             \
		exemple-setitimer-1          \
		exemple-setitimer-2          \
		exemple-timer-create         \
		exemple-timerfd              \
		exemple-clock                \
		exemple-times-1              \
		exemple-times-2              \
		exemple-rusage               \
		exemple-getrlimit            \

all : ${EXECUTABLES}

clean : 
	@rm -f core *.o a.out *~
	@rm -f ${EXECUTABLES}
