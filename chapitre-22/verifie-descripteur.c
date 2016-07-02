// ------------------------------------------------------------------
// verifie-descripteurs.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main (int argc, char * argv[])
{
	int i;
	int fd;
	struct stat status;

	for (i = 1; i < argc; i ++) {
		fprintf(stdout, "%s :", argv[i]);
		if (sscanf(argv[i], "%d", & fd) != 1) {
			fprintf(stdout, "invalide\n");
			continue;
		}
		if (fstat(fd, & status) != 0) {
			fprintf(stdout, "inaccessible\n");
			continue;
		}
		fprintf (stdout, "Ok (taille = %ld)\n", status.st_size);
	}
	return 0;
}
