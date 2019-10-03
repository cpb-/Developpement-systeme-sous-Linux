// ------------------------------------------------------------------
// exemple-fprintf-1.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main (void)
{
	int          d = INT_MAX;
	unsigned int u = UINT_MAX;
	unsigned int o = INT_MAX;
	unsigned int x = UINT_MAX;
	unsigned int X = UINT_MAX;
	double       f = 1.04;
	double       e = 1500;
	double       E = 101325;
	double       g = 1500;
	double       G = 0.00000101325;
	double       a = 1.0/65536.0;
	double       A = 0.125;
	char         c = 'a';
	char       * s = "chaine";
	void       * p = (void *) main;
	fprintf(stdout, " d=%d \n u=%u \n o=%o \n x=%x \n X=%X \n" 
	                " f=%f \n e=%e \n E=%E \n g=%g \n G=%G \n"
	                " a=%a \n A=%A \n c=%c \n s=%s \n p=%p \n",
	                d, u, o, x, X, f, e, E, g, G, a, A, c, s, p);
	return EXIT_SUCCESS;
}

