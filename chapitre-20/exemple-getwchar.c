// ------------------------------------------------------------------
// exemple-getwchar.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <wctype.h>

int main (void)
{
	wint_t  lu;
	wchar_t wcaracteres[17];
	int  emplacement = 0;
	int  rang = 0;
	setlocale(LC_ALL, "");
	wcaracteres[16] = '\0';
	while ((lu = getwchar()) != WEOF) {
		if ((rang = emplacement % 16) == 0)
			fprintf(stdout, "%08X  ", emplacement % 0xFFFFFFFF);
		fprintf(stdout, "%02X", lu); // ???
		if (rang == 7)
			fprintf(stdout, "-");
		else
			fprintf(stdout, " ");
		if (iswprint(lu))
			wcaracteres[rang] = lu;
		else
			wcaracteres[rang] = L' ';
		if (rang == 15)
			fprintf(stdout, " %ls\n", wcaracteres);
		emplacement ++;
	}
	while (rang < 15) {
		fprintf(stdout, "   ");
		wcaracteres[rang] = L'\0';
		rang ++;
	}
	fprintf(stdout, " %ls\n", wcaracteres);
	return EXIT_SUCCESS;
}
