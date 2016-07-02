SHELL=/bin/sh

CFLAGS = -Wall -g

EXECUTABLES=	exemple-memcmp			\
		exemple-stpncpy			\
		exemple-strncat			\
		exemple-strcasecmp		\
		exemple-mbstowcs                \
		exemple-strstr			\
		exemple-wcscoll			\
		exemple-strcasestr		\
		exemple-strtok			\
		exemple-strtok-r		\
		exemple-strsep			\


all : ${EXECUTABLES}


clean : 
	@rm -f core *.o *.out *~
	@rm -f ${EXECUTABLES}
