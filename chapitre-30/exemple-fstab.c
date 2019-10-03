// ------------------------------------------------------------------
// exemple-fstab.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <fstab.h>

int main (void)
{
	struct fstab *fstab;

	while (1) {
		if ((fstab = getfsent()) == NULL)
			break;
		fprintf(stdout, "spec = %s \n file = %s\n vfstype = %s \n"
				 " mntops = %s \n type = %s \n freq = %d \n"
				 " passno = %d \n",
				 fstab->fs_spec, fstab->fs_file,
				 fstab->fs_vfstype, fstab->fs_mntops,
				 fstab->fs_type, fstab->fs_freq,
				 fstab->fs_passno);
	}

	return EXIT_SUCCESS;
}	
		
