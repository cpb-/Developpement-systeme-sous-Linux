// ------------------------------------------------------------------
// exemple-isatty.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (void)
{
	if (isatty(STDIN_FILENO))
		fprintf(stdout, "stdin : %s\n", ttyname(STDIN_FILENO));
	else
		fprintf(stdout, "stdin : Pas un terminal ! \n");
	fprintf(stdout, "Terminal de controle : %s\n", ctermid(NULL));

	return EXIT_SUCCESS;
}
