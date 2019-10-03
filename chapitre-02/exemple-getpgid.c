// ------------------------------------------------------------------
// exemple-getpgid.c
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
	long int pgid;

	if (argc == 1) {
		fprintf(stdout, "%d: %d\n", getpid(), getpgid(0));
		return 0;
	}
	for (i = 1; i < argc; i ++) {
		if (sscanf(argv[i], "%ld", & pid) != 1) {
			fprintf(stderr, "invalid PID: %s\n", argv[i]);
		} else {
			pgid = (long) getpgid((pid_t) pid);
			if (pgid == -1)
				fprintf(stderr, "%ld: doesn't exist\n", pid);
			else
				fprintf(stderr, "%ld: %ld\n", pid, pgid);
		}
	}
	return 0;
}

