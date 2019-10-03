// ------------------------------------------------------------------
// exemple-shm.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>

int main (int argc, char * argv[])
{
	int  fd;
	int *counter;

	if (argc != 2) {
		fprintf(stderr, "Syntaxe : %s nom_segment\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((fd = shm_open(argv[1], O_RDWR | O_CREAT, 0600)) == -1) {
		perror(argv[1]);
		exit(EXIT_FAILURE);
	}
	if (ftruncate(fd, sizeof(int)) != 0) {
		perror("ftruncate");
		exit(EXIT_FAILURE);
	}
	counter = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if (counter == MAP_FAILED) {
		perror("mmap");
		exit(EXIT_FAILURE);
	}
	while (1) {
		(* counter) ++;
		fprintf(stdout, "counter = %d\n", (* counter));
		sleep(1);
	}

	return EXIT_SUCCESS;
}
