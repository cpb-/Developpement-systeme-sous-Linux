SHELL=/bin/sh

CFLAGS = -Wall -g

EXECUTABLES=                                    \
		exemple-getaddrinfo-01          \
		exemple-getaddrinfo-02          \
		exemple-gethostby		\
		exemple-gethostent		\
		exemple-getprotoby		\
		exemple-getprotoent		\
		exemple-getservby		\
		exemple-getservent-r		\
		exemple-inet-aton		\
		exemple-inet-netof		\
		exemple-inet-pton		\
		masque-reseau			\
		ordre-octets			\


all : ${EXECUTABLES}

clean : 
	@rm -f core* *.o *.out essai.* *~
	@rm -f ${EXECUTABLES}
