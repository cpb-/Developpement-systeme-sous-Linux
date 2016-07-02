SHELL=/bin/sh

CFLAGS = -Wall -g

EXECUTABLES=                             \
		exemple-sigqueue-1       \
		exemple-sigqueue-2       \
		exemple-siginfo          \
		exemple-sigwaitinfo      \
		exemple-sigtimedwait     \

all : ${EXECUTABLES}

clean : 
	@rm -f core *.o *.out *~
	@rm -f ${EXECUTABLES}
