// ------------------------------------------------------------------
// exemple-on-exit.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

void	gestion_sortie (int code, void * pointeur);

int main (void)
{
	FILE * fp;

	fp = fopen("exemple-atexit.c", "r");
	if (on_exit(gestion_sortie, (void *) fp) != 0)
		fprintf(stderr, "Erreur dans on_exit\n");

	fp = fopen("exemple-on-exit.c", "r");
	if (on_exit(gestion_sortie, (void *) fp) != 0)
		fprintf(stderr, "Erreur dans on_exit\n");

	if (on_exit(gestion_sortie, NULL) != 0)
		fprintf(stderr, "Erreur dans on_exit\n");

	fprintf(stdout, "Allez... on quitte en revenant de main()\n");
	return 4;
}

void gestion_sortie (int code, void * pointeur)
{
	fprintf(stdout, "Gestion Sortie appelee... code %d\n", code);
	if (pointeur == NULL) {
		fprintf(stdout, "Pas de fichier a fermer\n");
	} else {
		fprintf(stdout, "Fermeture d'un fichier\n");
		fclose((FILE *) pointeur);
	}
}

