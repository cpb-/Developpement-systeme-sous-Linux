// ------------------------------------------------------------------
// exemple-fputc.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void test_fputc (int value, FILE * fp)
{
	int ret;

	ret = fputc(value, fp);
	fprintf(stdout, "\n Ecrit : %d, ", value);
	fprintf(stdout, "ret = %d ", ret);
	if (ret == EOF)
		fprintf(stdout, "(EOF)");
	fprintf(stdout, "\n");
}


int main (void)
{
	test_fputc('A', stdout);
	test_fputc(65, stdout);
	test_fputc(UCHAR_MAX, stdout);
	test_fputc(-1, stdout);
	test_fputc('A', stdin);
	return EXIT_SUCCESS;
}
