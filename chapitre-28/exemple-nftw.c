// ------------------------------------------------------------------
// exemple-nftw.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#define _XOPEN_SOURCE 500
#include <ftw.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int delete_entry(const char *name, const struct stat *status,
         int attribut, struct FTW *unused)
{
	if (attribut == FTW_DP)
		return rmdir(name);

	return unlink(name);
}


int main (int argc, char * argv[])
{
	int	i;

	for (i = 1; i < argc; i ++)
		if (nftw(argv[i], delete_entry, 32,
                          FTW_DEPTH | FTW_PHYS | FTW_MOUNT) != 0)
			perror(argv[i]);

	return EXIT_SUCCESS;
}
