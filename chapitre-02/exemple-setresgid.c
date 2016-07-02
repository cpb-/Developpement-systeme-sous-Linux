// ------------------------------------------------------------------
// exemple-setresgid.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main (void)
{
	gid_t  gid_R, gid_E, gid_S;

	getresgid(& gid_R, & gid_E, & gid_S);
	printf("GID-R=%u, GID-E=%u, GID-S=%u\n", gid_R, gid_E,gid_S);
	printf("setresgid(-1, %u, %u)=%d\n",
	        gid_E, gid_R, setresgid(-1, gid_E, gid_R));
	getresgid(& gid_R, & gid_E, & gid_S);
	printf("GID-R=%u, GID-E=%u, GID-S=%u\n", gid_R, gid_E,gid_S);
	printf("setresgid(-1, %u, -1)=%d\n",
	        gid_S, setresgid(-1, gid_S, -1));
	getresgid(& gid_R, & gid_E, & gid_S);
	printf("GID-R=%u, GID-E=%u, GID-S=%u\n", gid_R, gid_E,gid_S);
	return 0;
}

