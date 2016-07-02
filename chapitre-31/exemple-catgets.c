// ------------------------------------------------------------------
// exemple-catgets.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <locale.h>
#include <nl_types.h>
#include <stdio.h>
#include <stdlib.h>
#include "exemple-catgets.h"

int main (void)
{
	nl_catd catalogue;
	char * chaine;

	setlocale(LC_ALL, "");
	if ((catalogue = catopen("msg-catgets", NL_CAT_LOCALE)) == (nl_catd) -1) {
		perror("catopen");
	}
	chaine = catgets(catalogue, premier_Set, premier_chaine_1, 
			"This is the first string in the first set");
	fprintf(stdout, "%s \n", chaine);
	chaine = catgets(catalogue, premier_Set, premier_chaine_2, 
			"and here is the second string in the first set.");
	fprintf(stdout, "%s \n", chaine);
	chaine = catgets(catalogue, second_Set, second_chaine_1, 
			"Now let's have a look at the 1st string in 2nd set,");
	fprintf(stdout, "%s \n", chaine);
	chaine = catgets(catalogue, second_Set, second_chaine_2, 
			"and finaly the second string in the second set.");
	fprintf(stdout, "%s \n", chaine);
	catclose(catalogue);
	return EXIT_SUCCESS;
}

