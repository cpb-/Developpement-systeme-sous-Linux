// ------------------------------------------------------------------
// exemple-serveur.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#define _GNU_SOURCE	/* Pour strfry() */
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

static char * nom_noeud = "anagramme.fifo";

static int repondre (const char * nom_fifo, char * chaine)
{
	FILE * reponse;
	int    fd;
	char * anagramme;

	if ((fd = open(nom_fifo, O_WRONLY)) >= 0) {
		reponse = fdopen(fd, "w");
		anagramme = strdup(chaine);
		strfry(anagramme);
		fprintf(reponse, "%s\n", anagramme);
		fclose(reponse);
		free(anagramme);
	}
	if ((strcasecmp(chaine, "FIN") == 0)
	 || (strcasecmp(nom_fifo, "FIN") == 0)) 
		return 1;
	return 0;
}

int main (void)
{
	FILE * fichier;
	int    fd;
	char   nom_fifo [128];
	char   chaine [128];

	if (mkfifo(nom_noeud, 0644) != 0) {
		fprintf(stderr, "Impossible de creer le noeud Fifo\n");
		exit(EXIT_FAILURE);
	}
	fd = open(nom_noeud, O_RDWR);
	fichier = fdopen(fd, "r");
	while (1) {
		fgets(nom_fifo, 128, fichier);
		if (nom_fifo[strlen(nom_fifo) - 1] == '\n')
			nom_fifo[strlen(nom_fifo) - 1] = '\0';
		fgets(chaine, 128, fichier);
		if (chaine[strlen(chaine) - 1] == '\n')
			chaine[strlen(chaine) - 1] = '\0';

		if (repondre(nom_fifo, chaine) != 0)
			break;
	}
	unlink(nom_noeud);
	return EXIT_SUCCESS;
}

