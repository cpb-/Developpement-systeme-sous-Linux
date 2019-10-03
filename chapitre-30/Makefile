SHELL=/bin/sh

CFLAGS = -Wall -g
LDFLAGS= -lm

EXECUTABLES= exemple-fstab        \
             exemple-gethostid    \
             exemple-gethostname  \
             exemple-getutent     \
             exemple-hasmntopt    \
             exemple-mtab         \
             exemple-statfs       \
             exemple-sysinfo      \
             exemple-syslog       \
             exemple-uname        \
             exemple-utmpname     \


all : ${EXECUTABLES}

clean : 
	@rm -f core* *.o *.out essai.* *~
	@rm -f ${EXECUTABLES}
