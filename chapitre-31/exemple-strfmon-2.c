// ------------------------------------------------------------------
// exemple-strfmon-2.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <locale.h>
#include <monetary.h>
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	int quantity[] = {
		1, 4, 3, 1, 1, 2, 0
	};
	char * reference[] = {
		"ABC", "DEF", "GHI", "JKL", "MNO", "PQR", NULL
	};
	double price[] = {
		1500, 2040, 560, 2500, 38400, 125, 0
	};
	int i;
	char format[80];
	double sum = 0.0;

	setlocale(LC_ALL, "");

	for (i = 0; reference[i] != NULL; i ++) {
		strfmon(format, 80, "%%5s : %#5n x %%d = %#5n\n",
		        price[i], price[i] * quantity[i]);
		fprintf(stdout, format, reference[i], quantity[i]);
		sum += price[i] * quantity[i];
	}
	strfmon(format, 80, "                  Total = %#5n\n", sum);
	fprintf(stdout, "%s", format);

	return EXIT_SUCCESS;
}


