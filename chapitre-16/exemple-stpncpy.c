// ------------------------------------------------------------------
// exemple-stpncpy.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#define _GNU_SOURCE

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void concatenate(char * dest, size_t max_size, ...)
{
	va_list arguments;
	char *	source;
	char *	result;
	size_t	string_size;

	result = dest;
	string_size = 0;

	va_start(arguments, max_size);

	while (1) {
		source = va_arg(arguments, char *);
		if (source == NULL)
			/* fin des arguments */
			break;
		result = stpncpy(result, source, max_size - string_size);
		string_size = result - dest;
		if (string_size >= max_size) {
			/* Ecraser le dernier caractere par un zero */
			result --;
			*result = '\0';
			break;
		}
	}
	va_end(arguments);
}

int main (void)
{
	char string[20];

	concatenate(string, 20, "123", "456", "7890", "1234", NULL);
	fprintf(stdout, "%s\n", string);

	concatenate(string, 20, "1234567890", "1234567890", "123", NULL);
	fprintf(stdout, "%s\n", string);

	return EXIT_SUCCESS;
}

