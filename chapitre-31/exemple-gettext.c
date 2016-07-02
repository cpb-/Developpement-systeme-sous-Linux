// ------------------------------------------------------------------
// exemple-gettext.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <libintl.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	setlocale(LC_ALL, "");

	textdomain("exemple-gettext");
	bindtextdomain("exemple-gettext", "/usr/share/locale");
	fprintf(stdout, gettext("This is the first string in the first set\n"));
	fprintf(stdout, gettext("and here is the second string in the first set.\n"));
	fprintf(stdout, gettext("Now let's have a look at the 1st string in 2nd set,\n"));
	fprintf(stdout, gettext("and finaly the second string in the second set.\n"));
	return EXIT_SUCCESS;
}

