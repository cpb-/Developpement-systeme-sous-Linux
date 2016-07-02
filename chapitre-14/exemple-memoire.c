// ------------------------------------------------------------------
// exemple-memoire.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main (int argc, char * argv [])
{
	int	i;
	int	nb_blocs;
	int	taille_bloc;
	char 	ligne_ps[80];
	char **	table = NULL;

	if ((argc != 3) 
	 || (sscanf(argv[1], "%d", & nb_blocs) != 1)
	 || (sscanf(argv[2], "%d", & taille_bloc) != 1)) {
		fprintf(stderr, "Syntaxe : %s Nb_blocs Taille_bloc\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((nb_blocs < 1) || (taille_bloc < 1)) {
		fprintf(stderr, "Valeurs invalides\n");
		exit(EXIT_FAILURE);
	}

	sprintf(ligne_ps, "ps un %ld", (long) getpid());

	fprintf(stdout, "Je demarre...\n");
	system(ligne_ps);

	fprintf(stdout, "J'alloue %d blocs de %d octets...", nb_blocs, taille_bloc);
	fflush(stdout);
	
	table = calloc(nb_blocs, sizeof (char *));
	if (table == NULL) {
		fprintf(stderr, "Echec\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < nb_blocs; i ++) {
		table[i] = malloc(taille_bloc);
		if (table[i] == NULL) {
			fprintf(stdout, "Echec\n");
			exit(EXIT_FAILURE);
		}
		memset(table[i], 1, taille_bloc);
	}
	fprintf(stdout, "Ok\n");
	system(ligne_ps);

	fprintf(stdout, "Je libere tous les blocs sauf le dernier\n");
	for (i = 0; i < nb_blocs - 1; i ++)
		free(table[i]);
	system(ligne_ps);

	fprintf(stdout, "Je libere le dernier bloc..\n");
	free(table[nb_blocs - 1]);
	system(ligne_ps);

	return EXIT_SUCCESS;
}
