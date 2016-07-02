// ------------------------------------------------------------------
// exemple-getuid.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <unistd.h>

int main(void)
{
	fprintf(stdout, "  UID reel = %u, UID effectif = %u\n",
 	        getuid(), geteuid());
	return 0;
}

