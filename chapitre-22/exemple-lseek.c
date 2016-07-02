// ------------------------------------------------------------------
// exemple-lseek.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main (void)
{
	int	fd;
	pid_t	pid_fils;
	off_t	position;

	fd = open("essai.lseek", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	// On ecrit quelques octets
	if (write(fd, "ABCDEFGHIJ", 10) != 10) {
		perror("write");
		exit(EXIT_FAILURE);
	}	
	// Puis on separe les processus
	if ((pid_fils = fork()) < 0) {
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid_fils != 0) {
		// Processus pere
		position = lseek(fd, 0, SEEK_CUR);
		fprintf(stderr, "Pere : position = %ld\n", position);
		sleep(1);
		position = lseek(fd, 0, SEEK_CUR);
		fprintf(stderr, "Pere : position = %ld\n", position);
		lseek(fd, 5, SEEK_SET);
		fprintf(stderr, "Pere : deplacement en position 5\n");
		waitpid(pid_fils, NULL, 0);
	} else {
		// Processus fils
		position = lseek(fd, 0, SEEK_CUR);
		fprintf(stderr, "Fils : position = %ld\n", position);
		lseek(fd, 2, SEEK_SET);
		fprintf(stderr, "Fils : deplacement en position 2\n");
		sleep(2);
		position = lseek(fd, 0, SEEK_CUR);
		fprintf(stderr, "Fils : position = %ld\n", position);
	}	
	close(fd);
	return EXIT_SUCCESS;
}

