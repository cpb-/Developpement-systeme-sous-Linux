SHELL=/bin/sh

CFLAGS = -Wall -g 

EXECUTABLES=                                 \
		exemple-gettimeofday-1       \
		exemple-gettimeofday-2       \
		exemple-clock-gettime        \
		exemple-localtime            \
		exemple-ctime                \
		exemple-strftime             \
		exemple-strptime             \
		exemple-getdate              \
		exemple-tzname               \

all : ${EXECUTABLES}

clean : 
	@rm -f core *.o a.out *~
	@rm -f ${EXECUTABLES}
