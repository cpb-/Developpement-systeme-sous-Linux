// ------------------------------------------------------------------
// exemple-sigqueue-1.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void usage(const char *name)
{
	fprintf(stderr, "usage: %s [-signal] [value] pid\n", name);
	exit(EXIT_FAILURE);
}

int main (int argc, char * argv [])
{
	int   num;
	int   pid;
	union sigval value;

	switch(argc) {
		case 4:
			if (sscanf(argv[1], "%d", &num) != 1)
				usage(argv[0]);
			if (sscanf(argv[2], "%d", &value.sival_int) != 1)
				usage(argv[0]);
			if (sscanf(argv[3], "%d", &pid) != 1)
				usage(argv[0]);
			if (num >= 0)
				usage(argv[0]);
			break;
		case 3:
			if (sscanf(argv[1], "%d", &num) != 1)
				usage(argv[0]);
			if (sscanf(argv[2], "%d", &pid) != 1)
				usage(argv[0]);
			if (num >= 0) {
				value.sival_int = num;
				num = -SIGTERM;
			} else {
				value.sival_int = 0;
			}
			break;
		case 2:
			if (sscanf(argv[1], "%d", &pid) != 1)
				usage(argv[0]);
			num = -SIGTERM;
			value.sival_int = 0;
			break;
		default:
			usage(argv[0]);
	}
	if (sigqueue((pid_t) pid, -num, value) < 0) {
		perror("sigqueue");
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

