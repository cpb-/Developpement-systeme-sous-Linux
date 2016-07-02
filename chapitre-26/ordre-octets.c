// ------------------------------------------------------------------
// ordre-octets.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[])
{
	unsigned short int s_i;
	unsigned char *    ch;
	int                i;

	if ((argc != 2) || (sscanf (argv[1], "%hi", & s_i) != 1)) {
		fprintf (stderr, "Syntaxe : %s entier \n", argv[0]);
		exit (EXIT_FAILURE);
	}
	ch = (unsigned char *) & s_i;
	fprintf(stdout, "0x%04X represente ainsi ", s_i);
	for (i = 0; i < sizeof(short int); i ++)
		fprintf(stdout, "%02X ", ch[i]);
	fprintf(stdout, "\n");
	return EXIT_SUCCESS;
}

