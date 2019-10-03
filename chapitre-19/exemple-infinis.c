// ------------------------------------------------------------------
// exemple-infinis.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#define _XOPEN_SOURCE 600

#include <errno.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display_number(const char *string, double d)
{
	fprintf(stdout, "%s", string);
	if (isnan(d))
		fprintf(stdout, "Indefini\n");
	else if (isinf(d) == 1)
		fprintf(stdout, "+Infini\n");
	else if (isinf(d) == -1)
		fprintf(stdout, "-Infini\n");
	else
		fprintf(stdout, "%f\n", d);
}

int main (void)
{
	double	d;

	d = +0.0;
	d = 1.0 / d;
	display_number("1 / +0 = ", d);
	d = -0.0;
	d = 1.0 / d;
	display_number("1 / -0 = ", d);
	d = 0.0 / 0.0;
	display_number("0 /  0 = ", d);
	d = log (0.0);
	display_number("log(0) = ", d);
	d = log (-1.0);
	display_number("log(-1)= ", d);
	d = MAXFLOAT;
	display_number("MAXFLOAT = ", d);
	d = exp(MAXFLOAT);
	display_number("exp(MAXFLOAT)= ", d);

	return EXIT_SUCCESS;
}

