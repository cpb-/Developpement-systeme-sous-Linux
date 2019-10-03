CFLAGS = -Wall -g

EXEMPLES=                  \
    exemple-fork           \
    exemple-getuid         \
    exemple-setuid         \
    exemple-setreuid       \
    exemple-setresuid      \
    exemple-getgroups      \
    exemple-setgroups      \
    exemple-setresgid      \
    exemple-getpgid        \
    exemple-getpgrp        \
    exemple-getsid         \

all : ${EXEMPLES}

clean : 
	@rm -f core *.o *.out *.bb *.bbg *.gcov *.da *~
	@rm -f ${EXEMPLES}
