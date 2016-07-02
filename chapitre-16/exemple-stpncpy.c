// ------------------------------------------------------------------
// exemple-stpncpy.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#define _GNU_SOURCE
	
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void concatenation (char * destination, size_t taille_maxi, ...)
{
	va_list arguments;
	char *	source;
	char *	retour;
	size_t	taille_chaine;

	retour = destination;
	taille_chaine = 0;

	va_start(arguments, taille_maxi);

	while (1) {
		source = va_arg(arguments, char *);
		if (source == NULL)
			/* fin des arguments */
			break;
		retour = stpncpy(retour, source, taille_maxi - taille_chaine);
		taille_chaine = retour - destination;
		if (taille_chaine == taille_maxi) {
			/* Ecraser le dernier caractere par un zero */
			retour --; 
			* retour = '\0';
			break;
		}
	}
	va_end(arguments);
}

int main (void)
{
	char chaine[20];

	concatenation(chaine, 20, "123", "456", "7890", "1234", NULL);
	fprintf(stdout, "%s\n", chaine);

	concatenation(chaine, 20, "1234567890", "1234567890", "123", NULL);
	fprintf(stdout, "%s\n", chaine);

	return EXIT_SUCCESS;
}

