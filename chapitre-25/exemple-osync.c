// ------------------------------------------------------------------
// exemple-osync.c
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
	int fd;
	char buffer[256];
	int i;

	if (argc != 3) {
		fprintf(stderr, "Syntaxe : %s fichier sync \n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((argv[2][0] == 'o') || (argv[2][0] == 'O')) {
		fprintf(stdout, "Ecritures synchronisees \n");
		if ((fd = open(argv[1], O_RDWR | O_CREAT | O_SYNC, 0644)) < 0) {
			perror("open");
			exit(EXIT_FAILURE);
		}
	} else {
		fprintf(stdout, "Ecritures non-synchronisees \n");
		if ((fd = open(argv[1], O_RDWR | O_CREAT, 0644)) < 0) {
			perror("open");
			exit(1);
		}
	}
	for (i = 0; i < 500000; i ++) 
		if (write(fd, buffer, 256) < 0) {
			perror("write");
			exit(EXIT_FAILURE);
		}
	fsync(fd);
	close(fd);
	return EXIT_SUCCESS;
}

