// ------------------------------------------------------------------
// exemple-strtof.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#define _GNU_SOURCE

#include <errno.h>
#include <limits.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
	char   string[128];
	char * start;
	char * end;
	float  value;
	
	setlocale(LC_ALL, "");
	while (fgets(string, 128, stdin) != NULL) {
		if (string[strlen(string) - 1] == '\n')
			string[strlen(string) - 1] = '\0';
		for (end = start = string; * end != '\0'; start = end) {
 			errno = 0;
			value = strtof(start, & end);
			if (end == start) {
				fprintf(stdout, "Erreur \n");
				break;
			}	
			if (errno == ERANGE)
				fprintf(stdout, "Debordement ! \n");
			else 
				fprintf(stdout, "Lu : %f \n", value);
		}	
	}

	return EXIT_SUCCESS;
}

