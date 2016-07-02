// ------------------------------------------------------------------
// exemple-vsnprintf.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * alloc_printf (const char * format, ...);

int main (void)
{
	char *	chaine;
	char *  seizecars = "0123456789ABCDEF";
	chaine = alloc_printf(" %s %s",
	                      seizecars, seizecars);
	if (chaine != NULL) {
		fprintf(stdout, "Chaine de %d caracteres\n%s\n",
		                 strlen(chaine), chaine);
		free(chaine);
	}
	chaine = alloc_printf(" %s  %s  %s  %s",
	                      seizecars, seizecars, seizecars, seizecars);
	if (chaine != NULL) {
		fprintf(stdout, "Chaine de %d caracteres\n%s\n",
		                 strlen(chaine), chaine);
		free(chaine);
	}
	return EXIT_SUCCESS;
}


char * alloc_printf (const char * format, ...)
{
	va_list	arguments;
	char *	retour = NULL;
	int	taille = 64;
	int	nb_ecrits;
	va_start(arguments, format);
	while (1) {
		retour = realloc(retour, taille);
		if (retour == NULL)
			break;
		nb_ecrits = vsnprintf(retour, taille, format, arguments);
		if ((nb_ecrits >= 0) && (nb_ecrits < taille))
			break;
		taille = taille + 64;
	}
	va_end(arguments);
	return retour;
}

