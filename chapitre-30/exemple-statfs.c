// ------------------------------------------------------------------
// exemple-statfs.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <sys/vfs.h>

int main (int argc, char * argv[])
{
	struct statfs	etat;
	int	i;
	for (i = 1; i < argc; i ++) {
		if (statfs(argv[i], & etat) < 0) {
			perror(argv[i]);
			continue;
		}
		fprintf(stdout, "%s : 1 bloc = %d octets \n"
		                "    total %ld blocs \n"
		                "    libre %ld blocs \n"
		                "    disponible %ld blocs \n",
			argv [i],  etat.f_bsize,
			etat.f_blocks, etat.f_bfree, etat.f_bavail);
	}
	return EXIT_SUCCESS;
}
