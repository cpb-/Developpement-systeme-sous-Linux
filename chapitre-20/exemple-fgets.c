// ------------------------------------------------------------------
// exemple-fgets.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * alloc_fgets (FILE * fp);

int main (void)
{
	char * chaine;
	while (1) {
		chaine = alloc_fgets(stdin);
		if (chaine == NULL)
			// Pas assez de memoire
		break;
		if ((chaine[0] == '\n') || (chaine[0] == '\0'))
			// Chaine vide... on quitte
			break;
		fprintf(stdout, "%d caracteres\n", strlen(chaine));
		free(chaine);
	}
	return EXIT_SUCCESS;
}


char * alloc_fgets (FILE * fp)
{
	char *	retour = NULL;
	char *  a_ecrire = NULL;
	int	taille = 64;

	retour = malloc (taille);
	retour[0] = '\0';
	a_ecrire = retour;
	while (1) {
		if (fgets (a_ecrire, 64, fp) == NULL)
			break;
		if (a_ecrire[strlen(a_ecrire)-1] == '\n')
			a_ecrire[strlen(a_ecrire)-1] = '\0';
		if (strlen (a_ecrire) < 63)
			break;
		// On se place sur le caractere nul final
		a_ecrire = a_ecrire + 63; 
		// Et on agrandit egalement le buffer de 63 caracteres
		taille += 63;
		retour = realloc (retour, taille);
		if (retour == NULL)
			break;
	}
	return (retour);
}


