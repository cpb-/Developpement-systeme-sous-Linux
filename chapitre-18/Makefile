SHELL=/bin/sh

CFLAGS = -Wall -g
LDFLAGS= -lcrypt
LOADLIBES= -lcrypt

EXECUTABLES=  \
		exemple-crypt       \
		exemple-crypt-2     \
		exemple-regcomp     \
		exemple-strfry      \


all : ${EXECUTABLES}


clean : 
	@rm -f core *.o *.out *~
	@rm -f ${EXECUTABLES}
