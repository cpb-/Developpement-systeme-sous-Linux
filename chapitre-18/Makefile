SHELL=/bin/sh

CFLAGS = -Wall -g
LDFLAGS= -lcrypt
LOADLIBES= -lcrypt

EXECUTABLES=	exemple-crypt			\
		exemple-crypt-2			\
		des-crypte			\
		des-decrypte			\
		exemple-ecb-crypt		\
		exemple-regcomp			\
		exemple-strfry			\


all : ${EXECUTABLES}

des-crypte :
	ln -sf exemple-ecb-crypt des-crypte

des-decrypte :
	ln -sf exemple-ecb-crypt des-decrypte


clean : 
	@rm -f core *.o *.out *~
	@rm -f ${EXECUTABLES}
