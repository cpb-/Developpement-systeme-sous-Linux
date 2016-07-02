// ------------------------------------------------------------------
// exemple-fcntl-4.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char * argv[])
{
	char    chaine[80];
	int             fd;
	struct flock flock;
	
	if (argc != 2) {
		fprintf(stderr, "Syntaxe : %s nom_fichier\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDWR | O_CREAT | O_EXCL, 02644);	
	if (fd < 0) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	write(fd, "ABCDEFGHIJ", 10);

	flock.l_type = F_WRLCK;
	flock.l_start = 0;
	flock.l_whence = SEEK_SET;
	flock.l_len = 10;

	if (fcntl(fd, F_SETLK, & flock) < 0) {
		perror("fcntl");	
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "Verrou OK\n");
	fgets(chaine, 80, stdin);
	close(fd);
	return EXIT_SUCCESS;
}

