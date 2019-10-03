// ------------------------------------------------------------------
// exemple-client.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
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
	FILE * answer;
	int    fd;
	char   fifo_name[128];
	char   string[128];

	fprintf(stdout, "Chaine a traiter : ");
	if (fgets(string, 128, stdin) == NULL)
		exit(EXIT_SUCCESS);
	sprintf(fifo_name, "anagramme.%ld", (long)getpid());
	if (mkfifo(fifo_name, 0644) != 0) {
		fprintf(stderr, "Impossible de creer la fifo\n");
		exit(EXIT_FAILURE);
	}

	if ((fd = open("anagramme.fifo", O_WRONLY)) < 0) {
		fprintf(stderr, "Impossible d'ouvrir la fifo du serveur\n");
		exit(EXIT_FAILURE);
	}
	question = fdopen(fd, "w");
	fprintf(question, "%s\n%s", fifo_name, string);
	fclose(question);

	fd = open(fifo_name, O_RDONLY);
	answer = fdopen(fd, "r");

	if (fgets(string, 128, answer) != NULL)
		fprintf(stdout, "Reponse = %s\n", string);
	else
		perror("fgets");
	fclose(answer);
	unlink(fifo_name);

	return EXIT_SUCCESS;
}

