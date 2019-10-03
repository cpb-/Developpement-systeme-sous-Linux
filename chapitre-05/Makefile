SHELL=/bin/sh

CFLAGS = -Wall -g

EXECUTABLES=	exemple-assert		\
		exemple-atexit		\
		exemple-exit-1		\
		exemple-exit-2		\
		exemple-on-exit		\
		exemple-perror		\
		exemple-strerror	\
		exemple-wait-1		\
		exemple-wait-2		\
		exemple-waitid		\
		exemple-zombie-1	\
		exemple-zombie-2

all : ${EXECUTABLES}

clean : 
	@rm -f core *.o a.out *~
	@rm -f ${EXECUTABLES}
