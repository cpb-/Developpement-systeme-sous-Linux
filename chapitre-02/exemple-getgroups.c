// ------------------------------------------------------------------
// exemple-getgroups.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

int main (void)
{
	int  taille;
	gid_t * table_gid = NULL;
	int  i;

	if ((taille = getgroups(0, NULL)) < 0) {
		fprintf(stderr, "Erreur getgroups, errno = %d\n", errno);
		return 1;
	}

	if ((table_gid = calloc(taille, sizeof(gid_t))) == NULL) {
		fprintf(stderr, "Erreur  calloc, errno = %d\n", errno);
		return 1;
	}

	if (getgroups(taille, table_gid) < 0) {
		fprintf(stderr, "Erreur getgroups, errno = %d\n", errno);
		return 1;
	}
	for (i = 0; i < taille; i ++)
		fprintf(stdout, "%u ", table_gid[i]);
	fprintf(stdout, "\n");

	free(table_gid);
	return 0;
}

