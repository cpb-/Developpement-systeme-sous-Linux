// ------------------------------------------------------------------
// exemple-strftime.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <limits.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char * argv[])
{
	int         i;
	int         lg;
	char *      buffer;
	struct tm * tm;
	time_t      heure;

	setlocale(LC_ALL, "");

	time(& heure);
	tm = localtime(& heure);

	for (i = 1; i < argc; i ++) {
		fprintf(stdout, "%s : ", argv[i]);
		lg = strftime(NULL, SSIZE_MAX, argv[1], tm);
		if (lg > 0) {
			buffer = malloc(lg + 1);
			if (buffer == NULL) {
				perror("malloc");
				exit(EXIT_FAILURE);
			}
			strftime(buffer, lg + 1, argv[i], tm);
			fprintf(stdout, "%s", buffer);
			free(buffer);
		}
		fprintf(stdout, "\n");
	}
	return EXIT_SUCCESS;
}
