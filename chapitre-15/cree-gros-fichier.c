// ------------------------------------------------------------------
// cree-gros-fichier.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main (int argc, char * argv[])
{
	int i;
	int fd;
	char * bloc;
	int nb_mega;

	if ((argc != 3) || (sscanf(argv[2], "%d", & nb_mega) != 1)) {
		fprintf(stderr, "Syntaxe : %s fichier nb_mega\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 0) {
		perror(argv[1]);
		exit(EXIT_FAILURE);
	}
	if ((bloc = malloc(1024*1024)) == NULL) {
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	for (i = 0 ; i < nb_mega; i ++) {
		memset(bloc, i % 255, 1024*1024);
		if (write(fd, bloc, 1024*1024) < 0) {
			perror("write");
			exit(EXIT_FAILURE);
		}
	}
	close(fd);
	return EXIT_SUCCESS;
}

