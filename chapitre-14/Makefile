SHELL=/bin/sh

CFLAGS = -Wall -g

EXECUTABLES=                               \
		exemple-alloca             \
		exemple-calloc-1           \
		exemple-calloc-2           \
		exemple-calloc-3           \
		exemple-malloc-1           \
		exemple-malloc-2           \
		exemple-check              \
		exemple-memoire            \
		exemple-mtrace-1           \
		exemple-mtrace-2           \
		exemple-debordement        \
		exemple-fuite              \


all : ${EXECUTABLES}

clean : 
	@rm -f core *.o *.out *~
	@rm -f ${EXECUTABLES}
