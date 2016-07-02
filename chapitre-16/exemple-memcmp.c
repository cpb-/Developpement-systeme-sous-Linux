// ------------------------------------------------------------------
// exemple-memcmp.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void affiche_resultats (unsigned char * bloc_1, unsigned char * bloc_2, int lg)
{
	int i;
	fprintf(stdout, "bloc_1 = ");
	for (i = 0; i < lg ; i ++)
		fprintf(stdout, "%02d ", bloc_1[i]);
	fprintf(stdout, "\n");
	fprintf(stdout, "bloc_2 = ");
	for (i = 0; i < lg ; i ++)
		fprintf(stdout, "%02d ", bloc_2[i]);
	fprintf(stdout, "\n");
	fprintf(stdout, "memcmp(bloc_1, bloc_2, %d) = %d\n",
			lg, memcmp(bloc_1, bloc_2, lg));
	fprintf (stdout, "\n");
}

int main (void)
{
	unsigned char bloc_1[4] = { 0x01, 0x02, 0x03, 0x04 };
	unsigned char bloc_2[4] = { 0x01, 0x02, 0x08, 0x04 };
	unsigned char bloc_3[4] = { 0x01, 0x00, 0x03, 0x04 };

	affiche_resultats(bloc_1, bloc_1, 4);
	affiche_resultats(bloc_1, bloc_2, 4);
	affiche_resultats(bloc_1, bloc_3, 4);

	return EXIT_SUCCESS;
}

