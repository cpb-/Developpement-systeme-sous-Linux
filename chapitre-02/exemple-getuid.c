// ------------------------------------------------------------------
// exemple-getuid.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <unistd.h>

int main(void)
{
	fprintf(stdout, "  Real-UID = %u, Effective-UID = %u\n",
	        getuid(), geteuid());
	return 0;
}

