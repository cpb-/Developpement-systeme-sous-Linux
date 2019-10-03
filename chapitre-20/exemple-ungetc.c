// ------------------------------------------------------------------
// exemple-ungetc.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void get_digit(FILE * fp);
void get_alpha(FILE * fp);

int main (void)
{
	int	c;
	while ((c = getc(stdin)) != EOF) {
		if (isdigit(c)) {
			ungetc(c, stdin);
			get_digit(stdin);
		} else if (isalpha(c)) {
			ungetc(c, stdin);
			get_alpha(stdin);
		}
	}
	return EXIT_SUCCESS;
}

void get_digit (FILE * fp)
{
	int c;

	fprintf(stdout, "Lecture numerique : ");
	while (isdigit(c = getc(fp))) {
		fprintf(stdout, "%c", c);
	}
	ungetc(c, fp);
	fprintf(stdout, "\n");
}

void get_alpha (FILE * fp)
{
	int c;

	fprintf(stdout, "Lecture alphabetique : ");
	while (isalpha(c = getc(fp))) {
		fprintf(stdout, "%c", c);
	}
	ungetc(c, fp);
	fprintf(stdout, "\n");
}

