// ------------------------------------------------------------------
// exemple-times-2.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/times.h>

int main (int argc, char * argv[])
{
	struct tms measure;
	double duration;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <command> \n", argv [0]);
		exit(EXIT_FAILURE);
	}
	system(argv[1]);
	times(&measure);
	duration = (double) measure.tms_cutime / sysconf(_SC_CLK_TCK);
	fprintf(stdout, "CPU time in user mode   = %f \n", duration);
	duration = (double) measure.tms_cstime / sysconf(_SC_CLK_TCK);
	fprintf(stdout, "CPU time in kernel mode = %f \n", duration);
	return EXIT_SUCCESS;
}

