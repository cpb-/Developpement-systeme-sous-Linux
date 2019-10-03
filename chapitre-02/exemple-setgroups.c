// ------------------------------------------------------------------
// exemple-setgroups.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#define _DEFAULT_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <grp.h>

int main (int argc, char * argv [])
{
	gid_t * gid_table = NULL;
	int     i;
	int     size;

	if (argc < 2) {
		fprintf(stderr, "Usage %s GID ...\n", argv[0]);
		return 1;
	}
	if ((gid_table = calloc(argc - 1, sizeof(gid_t))) == NULL) {
		fprintf(stderr, "Error in calloc(), errno = %d\n", errno);
		return 1;
	}
	for (i = 1; i < argc ; i ++) {
		if (sscanf(argv[i], "%u", &(gid_table[i - 1])) != 1) {
			fprintf(stderr, "invalid GID: %s\n", argv[i]);
			return 1;
		}
	}
	if (setgroups(i - 1, gid_table) < 0) {
		fprintf(stderr, "Error in setgroups(), errno = %d\n", errno);
		return 1;
	}
	free(gid_table);

	fprintf(stdout, "Verification : ");

	if ((size = getgroups(0, NULL)) < 0) {
		fprintf(stderr, "Error in getgroups(), errno = %d\n", errno);
		return 1;
	}

	if ((gid_table = calloc(size, sizeof(gid_t))) == NULL) {
		fprintf(stderr, "Error in calloc(), errno = %d\n", errno);
		return 1;
	}

	if (getgroups(size, gid_table) < 0) {
		fprintf(stderr, "Erreur in getgroups(), errno = %d\n", errno);
		return 1;
	}
	for (i = 0; i < size; i ++)
		fprintf(stdout, "%u ", gid_table[i]);
	fprintf(stdout, "\n");

	free(gid_table);

	return 0;
}
