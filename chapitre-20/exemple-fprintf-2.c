// ------------------------------------------------------------------
// exemple-fprintf-2.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	int	d;

	fprintf(stdout, "| %%6d  | %%+6d | %%-6d | %%-+6d| %% 6d | %%06d |\n");
	fprintf(stdout, "+------+------+------+------+------+------+\n");
	d = 0;
	fprintf(stdout, "|%6d|%+6d|%-6d|%-+6d|% 6d|%06d|\n", d, d, d, d, d, d);
	d = 1;
	fprintf(stdout, "|%6d|%+6d|%-6d|%-+6d|% 6d|%06d|\n", d, d, d, d, d, d);
	d = -2;
	fprintf(stdout, "|%6d|%+6d|%-6d|%-+6d|% 6d|%06d|\n", d, d, d, d, d, d);
	d = 100;
	fprintf(stdout, "|%6d|%+6d|%-6d|%-+6d|% 6d|%06d|\n", d, d, d, d, d, d);
	d = 1000;
	fprintf(stdout, "|%6d|%+6d|%-6d|%-+6d|% 6d|%06d|\n", d, d, d, d, d, d);
	d = 10000;
	fprintf(stdout, "|%6d|%+6d|%-6d|%-+6d|% 6d|%06d|\n", d, d, d, d, d, d);
	d = 100000;
	fprintf(stdout, "|%6d|%+6d|%-6d|%-+6d|% 6d|%06d|\n", d, d, d, d, d, d);
	return EXIT_SUCCESS;
}
