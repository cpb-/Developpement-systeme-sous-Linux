// ------------------------------------------------------------------
// exemple-complexe.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <complex.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
	
int main(void)
{
	double complex z;
	
	z = 0.5  + I * (sqrt(3)/2);
	fprintf(stdout, "Z : \n");
	fprintf(stdout, "  Partie reelle     : %f\n", creal(z));
	fprintf(stdout, "  Partie imaginaire : %f\n", cimag(z));
	fprintf(stdout, "  Module            : %f\n", cabs(z));
	fprintf(stdout, "  Argument          : %f\n", carg(z));

	z = conj(z);		
	fprintf(stdout, "\nConjugue de Z : \n");
	fprintf(stdout, "  Partie reelle     : %f\n", creal(z));
	fprintf(stdout, "  Partie imaginaire : %f\n", cimag(z));
	fprintf(stdout, "  Module            : %f\n", cabs(z));
	fprintf(stdout, "  Argument          : %f\n", carg(z));

	return EXIT_SUCCESS;
}
