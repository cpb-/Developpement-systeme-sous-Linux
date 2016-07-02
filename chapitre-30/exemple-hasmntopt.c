// ------------------------------------------------------------------
// exemple-hasmntopt.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <mntent.h>

int main (void)
{
	FILE * fichier;
	struct mntent * mntent;

	fichier = setmntent("/etc/fstab", "r");
	if (fichier == NULL)
		exit(EXIT_FAILURE);
	while (1) {
		mntent = getmntent(fichier);
		if (mntent == NULL)
			break;
		if (hasmntopt(mntent, "mand") != NULL)
			fprintf(stdout, "%s (%s)\n",
				mntent->mnt_fsname,
				mntent->mnt_dir);
	}
	endmntent(fichier);
	return EXIT_SUCCESS;
}
