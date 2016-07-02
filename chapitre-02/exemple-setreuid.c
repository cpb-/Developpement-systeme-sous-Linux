// ------------------------------------------------------------------
// exemple-setreuid.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main (void)
{
	uid_t  uid_reel;
	uid_t  uid_eff;

	uid_reel = getuid();
	uid_eff = geteuid();
	fprintf(stdout, "UID-R = %u,  UID-E = %u\n",
	                 getuid(), geteuid());
	fprintf(stdout, "setreuid(-1, %d) = %d\n", uid_reel,
	                 setreuid(-1, uid_reel));
	fprintf(stdout, "UID-R = %u,  UID-E = %u\n",
	                 getuid(), geteuid());
	fprintf(stdout, "setreuid(-1, %d) = %d\n", uid_eff,
	                 setreuid(-1, uid_eff));
	fprintf(stdout, "UID-R = %u,  UID-E = %u\n",
	                 getuid(), geteuid());
	fprintf(stdout, "setreuid(%d, -1) = %d\n", uid_eff,
	                 setreuid(uid_eff, -1));
	fprintf(stdout, "UID-R = %u,  UID-E = %u\n",
	                 getuid(), geteuid());
	return 0;
}

