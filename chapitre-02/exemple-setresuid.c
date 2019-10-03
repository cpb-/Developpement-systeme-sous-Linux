// ------------------------------------------------------------------
// exemple-setresuid.c
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
	uid_t  r_uid, e_uid, s_uid;

	getresuid(&r_uid, &e_uid, &s_uid);
	printf("R-UID=%u, E-UID=%u, S-UID=%u\n", r_uid, e_uid, s_uid);
	printf("setresuid(-1, %u, %u)=%d\n",
	       e_uid, r_uid, setresuid(-1, e_uid, r_uid));
	getresuid(&r_uid, &e_uid, &s_uid);
	printf("R-UID=%u, E-UID=%u, S-UID=%u\n", r_uid, e_uid, s_uid);
	printf("setresuid(-1, %u, -1)=%d\n",
	       s_uid, setresuid(-1, s_uid, -1));
	getresuid(&r_uid, &e_uid, &s_uid);
	printf("R-UID=%u, E-UID=%u, S-UID=%u\n", r_uid, e_uid, s_uid);

	return 0;
}
