// ------------------------------------------------------------------
// exemple-ungetc.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void	lecture_numerique   (FILE * fp);
void	lecture_alphabetique(FILE * fp);

int main (void)
{
	int	c;
	while ((c = getc(stdin)) != EOF) {
		if (isdigit(c)) {
			ungetc(c, stdin);
			lecture_numerique(stdin);
		} else if (isalpha(c)) {
			ungetc(c, stdin);
			lecture_alphabetique(stdin);
		}
	}
	return EXIT_SUCCESS;
}

void lecture_numerique (FILE * fp)
{
	int	c;
	fprintf(stdout, "Lecture numerique : ");
	while (1) {
		c = getc(fp);
		if (! isdigit(c))
			break;
		fprintf(stdout, "%c", c);
	}
	ungetc(c, fp);
	fprintf(stdout, "\n");
}
	
void lecture_alphabetique (FILE * fp)
{
	int	c;
	fprintf(stdout, "Lecture alphabetique : ");
	while (1) {
		c = getc(fp);
		if (! isalpha(c))
			break;
		fprintf(stdout, "%c", c);
	}
	ungetc(c, fp);
	fprintf(stdout, "\n");
}

