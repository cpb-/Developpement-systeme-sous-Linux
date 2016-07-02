// ------------------------------------------------------------------
// exemple-towupper.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wchar.h>
#include <wctype.h>

int main(int argc, char * argv[])
{
	int i, j, n;
	wchar_t * warg = NULL;

	setlocale(LC_ALL, "");
	for (i = 1; i < argc; i ++) {
		n = mbstowcs(NULL, argv[i], 0);
		warg = calloc(n, sizeof(wchar_t));
		if (warg == NULL) {
			perror("calloc");
			exit(EXIT_FAILURE);
		}
		mbstowcs(warg, argv[i], n);
		for (j = 0; j < n; j ++)
			if (iswlower(warg[j]))
				fprintf(stdout, "%lc", towupper(warg[j]));
			else
				fprintf(stdout, "%lc", (wint_t) warg[j]);
		free(warg);
		fprintf(stdout, "\n");
	}
	return 0;
}

