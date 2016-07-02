SHELL=/bin/sh

CFLAGS = -Wall -g

EXECUTABLES=	exemple-dup         \
		verifie-descripteur \
		exemple-fcntl       \
		exemple-fcntl-2     \
		exemple-fcntl-3     \
		exemple-fcntl-4     \
		exemple-lseek       \
		exemple-open        \
		exemple-open-2      \
		exemple-open-3      \
		exemple-write       \


all : ${EXECUTABLES}

clean : 
	@rm -f core* *.o *.out essai.* *~
	@rm -f ${EXECUTABLES}
