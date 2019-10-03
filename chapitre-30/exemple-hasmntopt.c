// ------------------------------------------------------------------
// exemple-hasmntopt.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <mntent.h>

int main (void)
{
	FILE *fp;
	struct mntent *mntent;

	fp = setmntent("/etc/fstab", "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);
	while (1) {
		mntent = getmntent(fp);
		if (mntent == NULL)
			break;
		if (hasmntopt(mntent, "mand") != NULL)
			fprintf(stdout, "%s (%s)\n",
				mntent->mnt_fsname,
				mntent->mnt_dir);
	}
	endmntent(fp);

	return EXIT_SUCCESS;
}
