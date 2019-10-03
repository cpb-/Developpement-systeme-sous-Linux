// ------------------------------------------------------------------
// exemple-getrlimit.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

void display_limit (char *label, int type);

int main (void)
{
	display_limit("CPU time in seconds ", RLIMIT_CPU);
	display_limit("File size           ", RLIMIT_FSIZE);
	display_limit("Data segment size   ", RLIMIT_DATA);
	display_limit("Stack segment size  ", RLIMIT_STACK);
	display_limit("Core file size      ", RLIMIT_CORE);
	display_limit("Processes count     ", RLIMIT_NPROC);
	display_limit("Open files count    ", RLIMIT_NOFILE);
	display_limit("Locked memory size  ", RLIMIT_NOFILE);
	return EXIT_SUCCESS;
}

void display_limit (char * label, int type)
{
	struct rlimit limit;

	if (getrlimit(type, &limit) != 0) {
		fprintf(stdout, "Unable to read limit %s\n",
		                label);
		return;
	}
	fprintf(stdout, "Limit for %s : ", label);
	if (limit.rlim_max == RLIM_INFINITY)
		fprintf(stdout, "unlimited ");
	else
		fprintf(stdout, "%lld ", (long long int) (limit . rlim_max));
	if (limit.rlim_cur == RLIM_INFINITY)
		fprintf(stdout, "(unlimited)\n");
	else
		fprintf(stdout, "(%lld)\n", (long long int) (limit . rlim_cur));
}

