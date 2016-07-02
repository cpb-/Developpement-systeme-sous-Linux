// ------------------------------------------------------------------
// exemple-gethostname.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (void)
{
	char * buffer = NULL;
	size_t taille = 8;

	buffer = malloc(taille);
	while (gethostname(buffer, taille) != 0) {
		if (errno != ENAMETOOLONG) {
			perror("gethostname");
			return EXIT_FAILURE;
		}
		taille += 8;
		buffer = realloc(buffer, taille);
	}
	fprintf(stdout, "%s\n", buffer);
	free(buffer);
	return EXIT_SUCCESS;
}

