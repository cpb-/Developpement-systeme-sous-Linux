// ------------------------------------------------------------------
// exemple-getdate.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char * argv[])
{
	struct tm *  tm;
	int          i;

	for (i = 1; i < argc; i ++) {
		fprintf(stdout, "%s : ", argv[i]);
		tm = getdate(argv[i]);
		if (tm == NULL)
			switch (getdate_err) {
				case 1 :
					fprintf(stdout, "DATEMSK indéfinie \n");
					break;
				case 2 :
				case 3 :
				case 4 :
				case 5 :
					fprintf(stdout, "Fichier de motifs invalide \n");
					break;
				case 6 :
					fprintf(stdout, "Pas assez de mémoire \n");
					break;
				case 7 :
					fprintf(stdout, "Conversion impossible \n");
					break; 
				case 8 :
					fprintf(stdout, "Valeur invalide \n");
					break;
			}
		else
			fprintf(stdout, "%s", asctime(tm));
	}
	return EXIT_SUCCESS;
}

