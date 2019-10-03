// ------------------------------------------------------------------
// exemple-setuid.c
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
	fprintf(stdout, " R-UID = %u,  E-UID = %u\n",
	        getuid(), geteuid());
	fprintf(stdout, " setuid(%d) = %d\n",
	        r_uid, setuid(r_uid));
	fprintf(stdout, " R-UID = %u,  E-UID = %u\n",
	        getuid(), geteuid());
	fprintf(stdout, " setuid(%d) = %d\n",
	        e_uid, setuid(e_uid));
	fprintf(stdout, " R-UID = %u,  E-UID = %u\n",
	        getuid(), geteuid());
	return 0;
}
