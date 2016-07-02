// ------------------------------------------------------------------
// exemple-strfmon-2.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <locale.h>
#include <monetary.h>
#include <stdio.h>
#include <stdlib.h>
	
int main (void)
{
	int quantite[] = {
		1, 4, 3, 1, 1, 2, 0
	};
	char * reference[] = {
		"ABC", "DEF", "GHI", "JKL", "MNO", "PQR", NULL
	};
	double prix[] = {
		1500, 2040, 560, 2500, 38400, 125, 0
	};
	int i;
	char format[80];
	double total = 0.0;

	setlocale(LC_ALL, "");
	
	for (i = 0; reference[i] != NULL; i ++) {
		strfmon(format, 80, "%%5s : %#5n x %%d = %#5n\n",
		        prix[i], prix[i] * quantite[i]);
		fprintf(stdout, format, reference[i], quantite[i]);
		total += prix[i] * quantite[i];
	}
	strfmon(format, 80, "                  Total = %#5n\n", total);
	fprintf(stdout, format);
	return EXIT_SUCCESS;
}

		
