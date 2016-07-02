SHELL=/bin/sh

CFLAGS = -Wall -g
LDFLAGS= -lrt
LOADLIBES=-lrt

EXECUTABLES=				\
		exemple-aio-read	\
		exemple-aio-suspend	\
		exemple-lio-listio	\
		exemple-nonblock-1	\
		exemple-nonblock-2	\
		exemple-osync		\
		exemple-select		\
		exemple-epoll           \


all : ${EXECUTABLES}

clean : 
	@rm -f core* *.o *.out essai.* *~
	@rm -f ${EXECUTABLES}
