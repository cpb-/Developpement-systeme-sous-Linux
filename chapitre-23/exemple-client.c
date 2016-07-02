// ------------------------------------------------------------------
// exemple-client.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main (void)
{
	FILE * question;
	FILE * reponse;
	int    fd;
	char   nom_fifo[128];
	char   chaine[128];

	fprintf(stdout, "Chaine a traiter : ");
	if (fgets(chaine, 128, stdin) == NULL)
		exit(EXIT_SUCCESS);
	sprintf(nom_fifo, "anagramme.%ld", (long)getpid());
	if (mkfifo(nom_fifo, 0644) != 0) {
		fprintf(stderr, "Impossible de creer la fifo\n");
		exit(EXIT_FAILURE);
	}

	if ((fd = open("anagramme.fifo", O_WRONLY)) < 0) {
		fprintf(stderr, "Impossible d'ouvrir la fifo du serveur\n");
		exit(EXIT_FAILURE);
	}
	question = fdopen(fd, "w");
	fprintf(question, "%s\n%s", nom_fifo, chaine);
	fclose(question);

	fd = open(nom_fifo, O_RDONLY);
	reponse = fdopen(fd, "r");

	if (fgets(chaine, 128, reponse) != NULL)
		fprintf(stdout, "Reponse = %s\n", chaine);
	else
		perror("fgets");
	fclose(reponse);
	unlink(nom_fifo);
	return EXIT_SUCCESS;
}

