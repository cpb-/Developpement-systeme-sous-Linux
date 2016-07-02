// ------------------------------------------------------------------
// exemple-is.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void affiche_caracteristiques (int c)
{
	fprintf(stdout, "%02X : ", (unsigned char) c);
	if (isalnum(c))  fprintf(stdout, "alphanumerique ");
	if (isalpha(c))  fprintf(stdout, "alphabetique ");
	if (isascii(c))  fprintf(stdout, "ascii ");
	if (iscntrl(c))  fprintf(stdout, "controle ");
	if (isdigit(c))  fprintf(stdout, "chiffre ");
	if (isgraph(c))  fprintf(stdout, "graphique ");
	if (islower(c))  fprintf(stdout, "minuscule ");
	if (isprint(c))  fprintf(stdout, "imprimable ");
	if (ispunct(c))  fprintf(stdout, "ponctuation ");
	if (isspace(c))  fprintf(stdout, "espace ");
	if (isupper(c))  fprintf(stdout, "majuscule ");
	if (isxdigit(c)) fprintf(stdout, "hexadecimal ");
	fprintf(stdout, "\n");
}

int main (void)
{
	int caractere;
	setlocale(LC_ALL, "");
	while ((caractere = getchar()) != EOF)
		affiche_caracteristiques(caractere);
	return EXIT_SUCCESS;
}

