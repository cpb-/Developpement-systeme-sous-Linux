// ------------------------------------------------------------------
// exemple-isw.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <wctype.h>

void affiche_caracteristiques (wint_t c)
{
	fprintf(stdout, "%lc : ", c);
	if (iswalnum(c))  fprintf(stdout, "alphanumerique ");
	if (iswalpha(c))  fprintf(stdout, "alphabetique ");
	if (iswcntrl(c))  fprintf(stdout, "controle ");
	if (iswdigit(c))  fprintf(stdout, "chiffre ");
	if (iswgraph(c))  fprintf(stdout, "graphique ");
	if (iswlower(c))  fprintf(stdout, "minuscule ");
	if (iswprint(c))  fprintf(stdout, "imprimable ");
	if (iswpunct(c))  fprintf(stdout, "ponctuation ");
	if (iswspace(c))  fprintf(stdout, "espace ");
	if (iswupper(c))  fprintf(stdout, "majuscule ");
	if (iswxdigit(c)) fprintf(stdout, "hexadecimal ");
	fprintf(stdout, "\n");
}

int main (void)
{
	wint_t caractere;
	setlocale(LC_ALL, "");
	while ((caractere = getwchar()) != WEOF)
		affiche_caracteristiques(caractere);
	return EXIT_SUCCESS;
}

