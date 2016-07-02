// ------------------------------------------------------------------
// exemple-pipe-4.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int invoque_processus (const char * commande, int fd[2])
{
	int	tube_1[2];
	int	tube_2[2];
	if ((pipe(tube_1) != 0) || (pipe(tube_2) != 0))
		return -1;
	switch (fork()) {
		case -1 :
			close(tube_1[0]); close(tube_1[1]);
			close(tube_2[0]); close(tube_2[1]);
			return -1;
		case 0 : 
			close(tube_1[1]);
			close(tube_2[0]);
			dup2(tube_1[0], STDIN_FILENO);
			dup2(tube_2[1], STDOUT_FILENO);
			system(commande);
			exit(EXIT_SUCCESS);
		default :
			close(tube_1[0]);
			close(tube_2[1]);
			fd[0] = tube_2[0];
			fd[1] = tube_1[1];
	}
	return 0;
}

int main (int argc, char * argv[])
{
	int    tube[2];
	FILE * fichier;
	char * contenu;
	struct stat status;
	char   c;

	if (argc != 2) {
		fprintf(stderr, "Syntaxe : %s fichier\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if (stat(argv[1], & status) != 0) {
		perror("stat");
		exit(EXIT_FAILURE);
	}
	if ((contenu = malloc(status.st_size)) == NULL) {
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	if ((fichier = fopen(argv[1], "r")) == NULL) {
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	if (fread(contenu, 1, status.st_size, fichier) != status . st_size) {
		perror("fread");
		exit(EXIT_FAILURE);
	}
	fclose(fichier);

	if (invoque_processus("wc -w", tube) != 0) {
		perror("invoque_processus");
		exit(EXIT_FAILURE);
	}
	write(tube[1], contenu, status.st_size);
	close(tube[1]);

	fprintf(stdout, "Nombre de mots :   ");
	while (read(tube[0], & c, 1) == 1)
		fputc(c, stdout);
	close(tube[0]);

	if (invoque_processus("wc -l", tube) != 0) {
		perror("invoque_processus");
		exit(EXIT_FAILURE);
	}
	write(tube[1], contenu, status.st_size);
	close(tube[1]);

	fprintf(stdout, "Nombre de lignes : ");
	while (read(tube[0], & c, 1) == 1)
		fputc(c, stdout);
	close(tube[0]);

	free(contenu);
	return EXIT_SUCCESS;
}

