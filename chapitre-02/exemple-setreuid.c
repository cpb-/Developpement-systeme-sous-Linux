// ------------------------------------------------------------------
// exemple-setreuid.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main (void)
{
	uid_t  r_uid;
	uid_t  e_uid;

	r_uid = getuid();
	e_uid = geteuid();
	fprintf(stdout, "R-UID = %u,  E-UID = %u\n",
	                 getuid(), geteuid());
	fprintf(stdout, "setreuid(-1, %d) = %d\n", r_uid,
	                 setreuid(-1, r_uid));
	fprintf(stdout, "R-UID = %u,  E-UID = %u\n",
	                 getuid(), geteuid());
	fprintf(stdout, "setreuid(-1, %d) = %d\n", e_uid,
	                 setreuid(-1, e_uid));
	fprintf(stdout, "R-UID = %u,  E-UID = %u\n",
	                 getuid(), geteuid());
	fprintf(stdout, "setreuid(%d, -1) = %d\n", e_uid,
	                 setreuid(e_uid, -1));
	fprintf(stdout, "R-UID = %u,  E-UID = %u\n",
	                 getuid(), geteuid());
	return 0;
}

