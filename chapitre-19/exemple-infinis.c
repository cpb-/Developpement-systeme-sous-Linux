// ------------------------------------------------------------------
// exemple-infinis.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#define _XOPEN_SOURCE 600

#include <errno.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void affiche_nombre (const char * chaine, double d)
{
	fprintf(stdout, "%s", chaine);
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
	affiche_nombre("1 / +0 = ", d);
	d = -0.0;
	d = 1.0 / d;
	affiche_nombre("1 / -0 = ", d);
	d = 0.0 / 0.0;
	affiche_nombre("0 /  0 = ", d);
	d = log (0.0);
	affiche_nombre("log(0) = ", d);
	d = log (-1.0);
	affiche_nombre("log(-1)= ", d);
	d = MAXFLOAT;
	affiche_nombre("MAXFLOAT = ", d);
	d = exp(MAXFLOAT);
	affiche_nombre("exp(MAXFLOAT)= ", d);
	return EXIT_SUCCESS;
}

