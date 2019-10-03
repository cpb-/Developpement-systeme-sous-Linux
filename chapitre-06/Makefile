SHELL=/bin/sh

CFLAGS = -Wall -g -pthread

EXECUTABLES=  \
		exemple-pthread-create-1     \
		exemple-pthread-create-2     \
		exemple-pthread-create-3     \
		exemple-pthread-create-4     \
		exemple-pthread-exit-1       \
		exemple-pthread-exit-2       \
		exemple-pthread-exit-3       \
		exemple-pthread-join         \
		exemple-pthread-detach       \
		exemple-pthread-attr         \
		exemple-pthread-mutex        \

all : ${EXECUTABLES}

clean : 
	@rm -f core *.o a.out *~
	@rm -f ${EXECUTABLES}
