// ------------------------------------------------------------------
// exemple-getsid.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main (int argc, char * argv[])
{
	int     i;
	long int pid;
	long int sid;

	if (argc == 1) {
		fprintf(stdout, "%d : %d\n", getpid(), getsid(0));
		return 0;
	}
	for (i = 1; i < argc; i ++) {
		if (sscanf(argv[i], "%ld", & pid) != 1) {
			fprintf(stderr, "invalid PID: %s\n", argv[i]);
		} else {
			sid = (long) getsid((pid_t)pid);
			if (sid == -1)
				fprintf(stderr, "%ld: doesn't exist\n", pid);
			else
				fprintf(stderr, "%ld: %ld\n", pid, sid);
		}
	}
	return 0;
}

 