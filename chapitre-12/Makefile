SHELL=/bin/sh

CFLAGS = -Wall -g

EXECUTABLES=	exemple-alarm		\
		exemple-fatal		\
		exemple-sigaction-1	\
		exemple-sigaction-2	\
		exemple-sigaction-3	\
		exemple-sigaltstack	\
		exemple-siglongjmp	\
		exemple-sigpending	\

all : ${EXECUTABLES}

clean : 
	@rm -f core *.o *.out *~
	@rm -f ${EXECUTABLES}
