// ------------------------------------------------------------------
// exemple-catgets.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <locale.h>
#include <nl_types.h>
#include <stdio.h>
#include <stdlib.h>
#include "exemple-catgets.h"

int main (void)
{
	nl_catd catalog;
	char *string;

	setlocale(LC_ALL, "");
	if ((catalog = catopen("msg-catgets", NL_CAT_LOCALE)) == (nl_catd) -1) {
		perror("catopen");
	}
	string = catgets(catalog, first_Set, first_string_1,
			"This is the first string in the first set");
	fprintf(stdout, "%s \n", string);
	string = catgets(catalog, first_Set, first_string_2,
			"and here is the second string in the first set.");
	fprintf(stdout, "%s \n", string);
	string = catgets(catalog, second_Set, second_string_1,
			"Now let's have a look at the 1st string in 2nd set,");
	fprintf(stdout, "%s \n", string);
	string = catgets(catalog, second_Set, second_string_2,
			"and finaly the second string in the second set.");
	fprintf(stdout, "%s \n", string);
	catclose(catalog);

	return EXIT_SUCCESS;
}

