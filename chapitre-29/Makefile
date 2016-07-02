SHELL=/bin/sh

CFLAGS = -Wall -g

EXECUTABLES=	exemple-readlink	\
		exemple-stat		\
		exemple-tailles		\
		exemple-truncate	\
		exemple-umask		\
		exemple-inotify         \


all : ${EXECUTABLES}

clean : 
	@rm -f core* *.o *.out essai.* *~
	@rm -f ${EXECUTABLES}
