SHELL=/bin/sh

CFLAGS = -Wall -g
LDFLAGS= -lm

EXECUTABLES=				\
		exemple-catgets		\
		exemple-gettext		\
		exemple-localeconv	\
		exemple-nl-langinfo	\
		exemple-numeric		\
		exemple-setlocale	\
		exemple-strfmon		\
		exemple-strfmon-2	\
		exemple-gettext.mo      \

all : ${EXECUTABLES}

exemple-gettext.mo: exemple-gettext.po
	msgfmt -o exemple-gettext.mo exemple-gettext.po

exemple-catgets: exemple-catgets.h

exemple-catgets.h: exemple-catgets.msg
	gencat -o msg-catgets -H exemple-catgets.h exemple-catgets.msg

clean : 
	@rm -f core* *.o *.out essai.* *~ exemple-catgets.h msg-catgets exemple-gettext.mo
	@rm -f ${EXECUTABLES}
