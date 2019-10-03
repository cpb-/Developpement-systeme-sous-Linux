// ------------------------------------------------------------------
// exemple-gethostname.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (void)
{
	char * buffer = NULL;
	size_t size = 8;

	buffer = malloc(size);
	while (gethostname(buffer, size) != 0) {
		if (errno != ENAMETOOLONG) {
			perror("gethostname");
			return EXIT_FAILURE;
		}
		size += 8;
		buffer = realloc(buffer, size);
	}
	fprintf(stdout, "%s\n", buffer);
	free(buffer);

	return EXIT_SUCCESS;
}

