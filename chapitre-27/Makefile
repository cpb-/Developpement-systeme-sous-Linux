SHELL=/bin/sh

CFLAGS = -Wall -g 

EXECUTABLES=					\
		delai-close			\
		exemple-client-anagramme	\
		exemple-demon-anagramme		\
		exemple-inet-anagramme		\
		exemple-reception-multicast	\
		exemple-serveur-anagramme	\
		exemple-serveur-daytime		\
		exemple-serveur-tcp		\
		stdin-2-udp			\
		tcp-2-stdout			\
		udp-2-stdout			\


all : ${EXECUTABLES}

clean : 
	@rm -f core* *.o *.out essai.* *~
	@rm -f ${EXECUTABLES}
