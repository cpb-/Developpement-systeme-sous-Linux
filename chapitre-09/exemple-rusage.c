// ------------------------------------------------------------------
// exemple-rusage.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>

int main (int argc, char * argv[])
{
	int which;
	struct rusage stats;

	if (argc == 1) {
		which = RUSAGE_SELF;
	} else {
		system(argv[1]);
		which = RUSAGE_CHILDREN;
	}
	if (getrusage(which, &stats) != 0) {
		fprintf(stderr, "Unable to get statistics \n");
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "Time in user mode  %ld s. %ld ms \n",
	        stats.ru_utime.tv_sec,
	        stats.ru_utime.tv_usec / 1000);
	fprintf(stdout, "Time in kernel mode  %ld s. %ld ms \n",
	        stats.ru_stime.tv_sec,
	        stats.ru_stime.tv_usec / 1000);
	fprintf(stdout, "\n");
	fprintf(stdout, "Minor page faults : %ld \n",
	        stats.ru_minflt);
	fprintf(stdout, "Major page faults : %ld \n",
	        stats.ru_majflt);
	fprintf(stdout, "Process swaps     : %ld \n",
	        stats.ru_nswap);
	return EXIT_SUCCESS;
}
