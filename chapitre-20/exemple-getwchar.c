// ------------------------------------------------------------------
// exemple-getwchar.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <wctype.h>

int main (void)
{
	wint_t  value;
	wchar_t string[17];
	int  index = 0;
	int  column = 0;

	setlocale(LC_ALL, "");
	string[16] = '\0';

	while ((value = getwchar()) != WEOF) {
		if ((column = index % 16) == 0)
			fprintf(stdout, "%08X  ", index % 0xFFFFFFFF);
		fprintf(stdout, "%02X", value); // ???
		if (column == 7)
			fprintf(stdout, "-");
		else
			fprintf(stdout, " ");
		if (iswprint(value))
			string[column] = value;
		else
			string[column] = L' ';
		if (column == 15)
			fprintf(stdout, " %ls\n", string);
		index ++;
	}
	while (column < 15) {
		fprintf(stdout, "   ");
		string[column] = L'\0';
		column ++;
	}
	fprintf(stdout, " %ls\n", string);
	return EXIT_SUCCESS;
}
