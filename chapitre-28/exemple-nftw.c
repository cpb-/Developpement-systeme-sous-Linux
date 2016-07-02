// ------------------------------------------------------------------
// exemple-nftw.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#define _XOPEN_SOURCE 500
#include <ftw.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int routine (const char * nom, const struct stat * etat,
         int attribut, struct FTW * status)
{
	if (attribut == FTW_DP)
		return rmdir(nom);
	return unlink(nom);
}

int main (int argc, char * argv[])
{
	int	i;
	for (i = 1; i < argc; i ++)
		if (nftw(argv[i], routine, 32,
                          FTW_DEPTH | FTW_PHYS | FTW_MOUNT) != 0)
			perror(argv[i]);
	return EXIT_SUCCESS;
}
