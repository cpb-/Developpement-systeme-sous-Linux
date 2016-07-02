SHELL=/bin/sh

CFLAGS = -Wall -g -pthread

EXECUTABLES=                                 \
		exemple-pthread-create-1     \
		exemple-pthread-create-2     \
		exemple-pthread-create-3     \
		exemple-pthread-create-4     \
		exemple-pthread-exit-1       \
		exemple-pthread-exit-2       \
		exemple-pthread-exit-3       \
		exemple-pthread-join-1       \
		exemple-pthread-detach-1     \
		exemple-pthread-detach-2     \
		exemple-pthread-attr-1       \
		exemple-pthread-mutex-1      \

all : ${EXECUTABLES}

clean : 
	@rm -f core *.o a.out *~
	@rm -f ${EXECUTABLES}
