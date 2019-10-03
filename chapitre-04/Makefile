SHELL=/bin/sh

CFLAGS = -Wall -g

EXECUTABLES=	exemple-argv		\
		exemple-environ		\
		exemple-environ-2	\
		exemple-getenv		\
		exemple-getopt		\
		exemple-getopt-long	\
		exemple-options		\
		exemple-putenv

all : ${EXECUTABLES}

exemple-options : exemple-options.c
	cc ${CFLAGS} -DLONG_OPTIONS -D_GNU_SOURCE exemple-options.c -o exemple-options

clean : 
	@rm -f core *.o *.out *~
	@rm -f ${EXECUTABLES}
