// ------------------------------------------------------------------
// exemple-wcscoll.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>

int main (int argc, char * argv[])
{
	int i, n;
	wchar_t * warg[2];

	int	compar;

	setlocale (LC_ALL, "");

	if (argc != 3) {
		fprintf(stderr, "Syntaxe : %s chaine_1 chaine_2\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	for (i = 0; i < 2; i ++) {
		n = mbstowcs(NULL, argv[i+1], 0)+1;
		warg[i] = calloc(n, sizeof(wchar_t));
		if (warg[i] == NULL) {
			perror("calloc");
			exit(EXIT_FAILURE);
		}
		mbstowcs(warg[i], argv[i+1], n);
	}

	compar = wcscoll(warg[0], warg[1]);
	fprintf(stdout, "%ls  %c %ls \n", warg[0],
			(compar > 0 ? '>' : (compar == 0 ? '=' :  '<' )),
			warg[1]);
	free(warg[1]);
	free(warg[0]);
			
	return EXIT_SUCCESS;
}
