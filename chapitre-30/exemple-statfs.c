// ------------------------------------------------------------------
// exemple-statfs.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <sys/vfs.h>

int main (int argc, char * argv[])
{
	struct statfs status;
	int	i;

	for (i = 1; i < argc; i ++) {
		if (statfs(argv[i], & status) < 0) {
			perror(argv[i]);
			continue;
		}
		fprintf(stdout, "%s : 1 bloc = %ld octets \n"
		                "    total %ld blocs \n"
		                "    libre %ld blocs \n"
		                "    disponible %ld blocs \n",
			argv [i],  status.f_bsize,
			status.f_blocks, status.f_bfree, status.f_bavail);
	}

	return EXIT_SUCCESS;
}
