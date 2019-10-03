// ------------------------------------------------------------------
// exemple-memcmp.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display_results(unsigned char * block_1, unsigned char * block_2, int lg)
{
	int i;

	fprintf(stdout, "block_1 = ");
	for (i = 0; i < lg ; i ++)
		fprintf(stdout, "%02d ", block_1[i]);
	fprintf(stdout, "\n");
	fprintf(stdout, "block_2 = ");
	for (i = 0; i < lg ; i ++)
		fprintf(stdout, "%02d ", block_2[i]);
	fprintf(stdout, "\n");
	fprintf(stdout, "memcmp(block_1, block_2, %d) = %d\n",
			lg, memcmp(block_1, block_2, lg));
	fprintf (stdout, "\n");
}

int main (void)
{
	unsigned char block_1[4] = { 0x01, 0x02, 0x03, 0x04 };
	unsigned char block_2[4] = { 0x01, 0x02, 0x08, 0x04 };
	unsigned char block_3[4] = { 0x01, 0x00, 0x03, 0x04 };

	display_results(block_1, block_1, 4);
	display_results(block_1, block_2, 4);
	display_results(block_1, block_3, 4);

	return EXIT_SUCCESS;
}

