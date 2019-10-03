// ------------------------------------------------------------------
// exemple-mbtowcs.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char * argv[])
{
	int i, j, n;
	wchar_t * warg;
	setlocale(LC_ALL, "");

	for (i = 1; i < argc; i ++) {
		fprintf(stdout, "Argument #%d:\n", i);
		fprintf(stdout, "  Sequence multi-octets : ");
		for (j = 0; argv[i][j] != '\0'; j ++)
			fprintf(stdout, "%02x ", (unsigned char) (argv[i][j]));
		fprintf(stdout, "\n");
		n = mbstowcs(NULL, argv[i], 0)+1;
		fprintf(stdout, "  Nb caracteres larges : %d\n", n);
		warg = calloc(n, sizeof(wchar_t));
		if (warg == NULL) {
			perror("calloc");
			exit(1);
		}
		mbstowcs(warg, argv[i], n);
		fprintf(stdout, "  Chaine wchar : %ls\n", warg);
		free(warg);
	}
	return 0;
}

