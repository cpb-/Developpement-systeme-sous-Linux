// ------------------------------------------------------------------
// exemple-lseek.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
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
	pid_t	child_pid;
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
	if ((child_pid = fork()) < 0) {
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (child_pid != 0) {
		// Processus parent
		position = lseek(fd, 0, SEEK_CUR);
		fprintf(stderr, "Parent : position = %ld\n", position);
		sleep(1);
		position = lseek(fd, 0, SEEK_CUR);
		fprintf(stderr, "Parent : position = %ld\n", position);
		lseek(fd, 5, SEEK_SET);
		fprintf(stderr, "Parent : deplacement en position 5\n");
		waitpid(child_pid, NULL, 0);
	} else {
		// Processus enfant
		position = lseek(fd, 0, SEEK_CUR);
		fprintf(stderr, "Enfant : position = %ld\n", position);
		lseek(fd, 2, SEEK_SET);
		fprintf(stderr, "Enfant : deplacement en position 2\n");
		sleep(2);
		position = lseek(fd, 0, SEEK_CUR);
		fprintf(stderr, "Enfant : position = %ld\n", position);
	}	
	close(fd);

	return EXIT_SUCCESS;
}

