// ------------------------------------------------------------------
// exemple-getline.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
	char  *string;
	size_t length;
	ssize_t size;

	for (;;) {
		length = 0;
		string = NULL;
		size = getline(& string, &length, stdin);
		if (size == -1)
			break;
		fprintf(stdout, "%ld caracteres lus\n", size);
		fprintf(stdout, "%ld caracteres alloues\n", length);
		free(string);
	}

	return EXIT_SUCCESS;
}

