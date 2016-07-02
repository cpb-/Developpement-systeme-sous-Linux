// ------------------------------------------------------------------
// exemple-inet-anagramme.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#define _GNU_SOURCE
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main (void)	
{
	char chaine[256];
	int  n;
	while (1) {
		if ((n = read(STDIN_FILENO, chaine, 256)) <= 1)
			break;
		while (isspace(chaine[n - 1]))
			n --;
		chaine[n] = '\0';
		strfry(chaine);
		write(STDOUT_FILENO, chaine, n);
	}
	return EXIT_SUCCESS;
}

