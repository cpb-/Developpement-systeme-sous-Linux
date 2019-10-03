// ------------------------------------------------------------------
// exemple-getchar.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main (void)
{
	int  value;
	char line[17];
	int  index = 0;
	int  column = 0;

	line[16] = '\0';
	while ((value = getchar()) != EOF) {
		if ((column = index % 16) == 0)
			fprintf(stdout, "%08X  ", index % 0xFFFFFFFF);
		fprintf(stdout, "%02X", value);
		if (column == 7)
			fprintf(stdout, "-");
		else
			fprintf(stdout, " ");
		if (isprint(value))
			line[column] = value;
		else
			line[column] = ' ';
		if (column == 15)
			fprintf(stdout, " %s\n", line);
		index ++;
	}
	while (column < 15) {
		fprintf(stdout, "   ");
		line[column] = '\0';
		column ++;
	}
	fprintf(stdout, " %s\n", line);

	return EXIT_SUCCESS;
}
