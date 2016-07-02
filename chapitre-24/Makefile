SHELL=/bin/sh

CFLAGS = -Wall -g -pthread
LDFLAGS= -pthread -lrt
LOADLIBES=-lrt

EXECUTABLES=	                       \
		exemple-mq-send        \
		exemple-mq-receive     \
		exemple-shm            \
		exemple-semaphore      \
		exemple-msgctl         \
		exemple-msgrcv         \
		exemple-msgsnd         \
		exemple-shmat          \


all : ${EXECUTABLES}

clean : 
	@rm -f core* *.o *.out essai.* *~
	@rm -f ${EXECUTABLES}
