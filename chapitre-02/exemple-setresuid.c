// ------------------------------------------------------------------
// exemple-setresuid.c
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
	uid_t  uid_R, uid_E, uid_S;

	getresuid(& uid_R, & uid_E, & uid_S);
	printf("UID-R=%u, UID-E=%u, UID-S=%u\n", uid_R, uid_E,uid_S);
	printf("setresuid(-1, %u, %u)=%d\n",
	       uid_E, uid_R, setresuid(-1, uid_E, uid_R));
	getresuid(& uid_R, & uid_E, & uid_S);
	printf("UID-R=%u, UID-E=%u, UID-S=%u\n", uid_R, uid_E,uid_S);
	printf("setresuid(-1, %u, -1)=%d\n",
	       uid_S, setresuid(-1, uid_S, -1));
	getresuid(& uid_R, & uid_E, & uid_S);
	printf("UID-R=%u, UID-E=%u, UID-S=%u\n", uid_R, uid_E,uid_S);
	return 0;
}
