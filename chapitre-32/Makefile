SHELL=/bin/sh

CFLAGS = -Wall -g

EXECUTABLES=				\
		client-pty		\
		exemple-flush		\
		exemple-getpass		\
		exemple-isatty		\
		exemple-pty		\
		exemple-raw		\
		exemple-serie		\
		exemple-socket		\
		exemple-system-shell    \
		serie-2-stdout		\
		stdin-2-serie		\


all : ${EXECUTABLES}

clean : 
	@rm -f core* *.o *.out essai.* *~
	@rm -f ${EXECUTABLES}
