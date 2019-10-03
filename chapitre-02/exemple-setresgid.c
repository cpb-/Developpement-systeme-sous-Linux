// ------------------------------------------------------------------
// exemple-setresgid.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main (void)
{
	gid_t r_gid, e_gid, s_gid;

	getresgid(&r_gid, &e_gid, &s_gid);
	printf("R-GID=%u, E-GID=%u, S-GID=%u\n", r_gid, e_gid, s_gid);
	printf("setresgid(-1, %u, %u)=%d\n",
	        e_gid, r_gid, setresgid(-1, e_gid, r_gid));
	getresgid(&r_gid, &e_gid, &s_gid);
	printf("R-GID=%u, E-GID=%u, S-GID=%u\n", r_gid, e_gid, s_gid);
	printf("setresgid(-1, %u, -1)=%d\n",
	        s_gid, setresgid(-1, s_gid, -1));
	getresgid(&r_gid, &e_gid, &s_gid);
	printf("R-GID=%u, E-GID=%u, S-GID=%u\n", r_gid, e_gid, s_gid);

	return 0;
}
