// ------------------------------------------------------------------
// exemple-semaphore.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <errno.h>
#include <fcntl.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char * argv[])
{
	int   i;
	sem_t * sem;

	if (argc != 2) {
		fprintf(stderr, "usage: %s nom_semaphore\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	sem = sem_open(argv[1], O_RDWR);
	if (sem == SEM_FAILED) {
		if (errno != ENOENT) {
			perror(argv[1]);
			exit(EXIT_FAILURE);
		}
		sem = sem_open(argv[1], O_RDWR | O_CREAT, 0666, 1);
		if (sem == SEM_FAILED) {
			perror(argv[1]);
			exit(EXIT_FAILURE);
		}
		fprintf(stderr, "[%d] Creation de %s\n", getpid(), argv[1]);
	}
	for (i = 0; i < 3;  i ++) {
		fprintf(stderr, "[%d] en attente...\n", getpid());
		sem_wait(sem);
		fprintf(stderr, "     [%d] tient le semaphore\n", getpid());
		sleep(4);
		fprintf(stderr, "     [%d] lache le semaphore\n", getpid());
		sem_post(sem);
		sleep(2);
	}	
	return EXIT_SUCCESS;
}
