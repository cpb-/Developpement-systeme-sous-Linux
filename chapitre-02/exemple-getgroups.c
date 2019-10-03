// ------------------------------------------------------------------
// exemple-getgroups.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

int main (void)
{
	int  size;
	gid_t * gid_table = NULL;
	int  i;

	if ((size = getgroups(0, NULL)) < 0) {
		fprintf(stderr, "Error in getgroups(), errno = %d\n", errno);
		return 1;
	}

	if ((gid_table = calloc(size, sizeof(gid_t))) == NULL) {
		fprintf(stderr, "Error in calloc(), errno = %d\n", errno);
		return 1;
	}

	if (getgroups(size, gid_table) < 0) {
		fprintf(stderr, "Error in getgroups(), errno = %d\n", errno);
		return 1;
	}
	for (i = 0; i < size; i ++)
		fprintf(stdout, "%u ", gid_table[i]);
	fprintf(stdout, "\n");

	free(gid_table);

	return 0;
}

