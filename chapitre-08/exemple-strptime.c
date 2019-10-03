// ------------------------------------------------------------------
// exemple-strptime.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#define  _XOPEN_SOURCE
#include <limits.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main (int argc, char * argv[])
{
	int         i;
	int         lg;
	time_t      now;
	struct tm   tm;
	struct tm * example;
	char *      buffer;
	char *      ret;

	setlocale(LC_ALL, "");

	time(&now);
	example = localtime(&now);
	memset(&tm, 0, sizeof(struct tm));

	for (i = 1; i < argc ; i ++) {
		lg = strftime(NULL, SSIZE_MAX, argv[i], example);
		if (lg > 0) {
			/* On alloue 2 octets de plus pour \n et \0 */
			buffer = malloc(lg + 2); /* retour à vérifier...*/
			strftime(buffer, lg + 2, argv[i], example);
			fprintf(stdout, "Format %s (example %s) : ",
					argv[i], buffer);
			while (1) {
				fgets(buffer, lg + 2, stdin);
				ret = strptime(buffer, argv[i], &tm);
				if (ret == NULL)
					fprintf(stdout, "Erreur > ");
				else
					break;
			}
			free(buffer);
		}
	}
	puts(asctime(&tm));
	return EXIT_SUCCESS;
}

