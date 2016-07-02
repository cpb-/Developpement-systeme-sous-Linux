// ------------------------------------------------------------------
// exemple-fcntl-3.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main (void)
{
	int	fd;
	int	pid;
	struct flock lock;

	// Creation d'un fichier avec quelques donnees
	if ((fd = open("essai.fcntl", O_RDWR | O_CREAT | O_TRUNC, 0644)) < 0){
		perror("open");
		exit(EXIT_FAILURE);
	}
	write(fd, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 26);
	if ((pid = fork()) == 0) {
		fprintf(stderr, "FILS : Verrou en Lecture de 0-1-2\n");
		lock.l_type = F_RDLCK;
		lock.l_whence = SEEK_SET;
		lock.l_start = 0;
		lock.l_len = 3;
		if (fcntl(fd, F_SETLKW, & lock) < 0)
			perror("FILS");
		else
			fprintf(stderr, "FILS : Ok\n");
		sleep(1);
		fprintf(stderr, "FILS : Verrou en Ecriture de 20-21-22\n");
		lock.l_type = F_WRLCK;
		lock.l_whence = SEEK_SET;
		lock.l_start = 20;
		lock.l_len = 3;
		if (fcntl(fd, F_SETLKW, & lock) < 0)
			perror("FILS");
		else
			fprintf(stderr, "FILS : Ok\n");
		sleep(2);
	} else {
		fprintf(stderr, "PERE : Verrou en Lecture de 18-19-20\n");
		lock.l_type = F_RDLCK;
		lock.l_whence = SEEK_SET;
		lock.l_start = 18;
		lock.l_len = 3;
		if (fcntl(fd, F_SETLKW, & lock) < 0)
			perror("PERE");
		else
			fprintf(stderr, "PERE : Ok\n");
		sleep(2);
		fprintf(stderr, "PERE : Verrou en Ecriture de 2-3\n");
		lock.l_type = F_WRLCK;
		lock.l_whence = SEEK_SET;
		lock.l_start = 2;
		lock.l_len = 2;
		if (fcntl(fd, F_SETLKW, & lock) < 0)
			perror("PERE");
		else
			fprintf(stderr, "PERE : Ok\n");
		fprintf(stderr, "PERE : Liberation du verrou 18-19-20\n");
		lock.l_type = F_UNLCK;
		lock.l_whence = SEEK_SET;
		lock.l_start = 18;
		lock.l_len = 3;
		if (fcntl(fd, F_SETLKW, & lock) < 0)
			perror("PERE");
		else
			fprintf(stderr, "PERE : Ok\n");
		waitpid(pid, NULL, 0);
	}
	return EXIT_SUCCESS;
}

