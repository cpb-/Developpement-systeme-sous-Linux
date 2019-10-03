// ------------------------------------------------------------------
// exemple-vsnprintf.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * alloc_printf (const char *format, ...);

int main (void)
{
	char *string;
	char *string_16 = "0123456789ABCDEF";

	string = alloc_printf(" %s %s",
	                      string_16, string_16);
	if (string != NULL) {
		fprintf(stdout, "Chaine de %lu caracteres\n%s\n",
		                 strlen(string), string);
		free(string);
	}
	string = alloc_printf(" %s  %s  %s  %s",
	                      string_16, string_16, string_16, string_16);
	if (string != NULL) {
		fprintf(stdout, "Chaine de %lu caracteres\n%s\n",
		                 strlen(string), string);
		free(string);
	}

	return EXIT_SUCCESS;
}


char * alloc_printf (const char *format, ...)
{
	va_list	args;
	char *ret_string = NULL;
	int	size = 64;
	int	written;

	while (1) {
		va_start(args, format);
		ret_string = realloc(ret_string, size);
		if (ret_string == NULL)
			break;
		written = vsnprintf(ret_string, size, format, args);
		if ((written >= 0) && (written < size))
			break;
		size = size + 64;
		va_end(args);
	}

	return ret_string;
}

