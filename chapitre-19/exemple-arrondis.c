// ------------------------------------------------------------------
// exemple-arrondis.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	double d;
	double floor_rounded;
	double ceil_rounded;
	double rint_rounded;
	int    integer;

	printf("double  floor() ceil()  rint()  (int)\n");
	for (d = -1.8; d < 1.9; d += 0.2) {
		floor_rounded = floor(d);
		ceil_rounded= ceil(d);
		rint_rounded = rint(d);
		integer = (int) d;
		printf("% 4.1f    % 4.1f    % 4.1f    % 4.1f    % 2d\n",
		        d, floor_rounded, ceil_rounded, rint_rounded, integer);
	}

	return EXIT_SUCCESS;
}
