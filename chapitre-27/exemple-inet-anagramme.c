// ------------------------------------------------------------------
// exemple-inet-anagramme.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#define _GNU_SOURCE
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main (void)	
{
	char string[256];
	int  n;

	while (1) {
		if ((n = read(STDIN_FILENO, string, 256)) <= 1)
			break;
		while (isspace(string[n - 1]))
			n --;
		string[n] = '\0';
		strfry(string);
		write(STDOUT_FILENO, string, n);
	}

	return EXIT_SUCCESS;
}

