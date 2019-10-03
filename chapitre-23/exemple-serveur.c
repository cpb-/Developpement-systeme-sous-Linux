// ------------------------------------------------------------------
// exemple-serveur.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#define _GNU_SOURCE	/* Pour strfry() */
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

static char *fifo_name = "anagramme.fifo";

static int reply(const char *filename, char *string)
{
	FILE *answer;
	int    fd;
	char *anagram;

	if ((fd = open(filename, O_WRONLY)) >= 0) {
		answer = fdopen(fd, "w");
		anagram = strdup(string);
		strfry(anagram);
		fprintf(answer, "%s\n", anagram);
		fclose(answer);
		free(anagram);
	}
	if ((strcasecmp(string, "END") == 0)
	 || (strcasecmp(filename, "END") == 0)) 
		return 1;
	return 0;
}

int main (void)
{
	FILE *fp;
	int   fd;
	char  filename[128];
	char  string[128];

	if (mkfifo(fifo_name, 0644) != 0) {
		fprintf(stderr, "Impossible de creer le noeud Fifo\n");
		exit(EXIT_FAILURE);
	}
	fd = open(fifo_name, O_RDWR);
	fp = fdopen(fd, "r");
	while (1) {
		fgets(filename, 128, fp);
		if (filename[strlen(filename) - 1] == '\n')
			filename[strlen(filename) - 1] = '\0';
		fgets(string, 128, fp);
		if (string[strlen(string) - 1] == '\n')
			string[strlen(string) - 1] = '\0';

		if (reply(filename, string) != 0)
			break;
	}
	unlink(fifo_name);
	return EXIT_SUCCESS;
}

