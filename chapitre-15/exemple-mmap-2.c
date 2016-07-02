// ------------------------------------------------------------------
// exemple-mmap-2.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>

int * entier;

void gestionnaire_sigusr1 (int num)
{
	fprintf(stdout, "Fils : * entier = %d\n", * entier);
	fflush(stdout);
}

int main (void)
{
	char * nom_fichier;
	int    fichier;
	pid_t  pid;	
	
	if (signal(SIGUSR1, gestionnaire_sigusr1) == SIG_ERR) {
		perror("signal");
		exit(EXIT_FAILURE);
	}
	if ((nom_fichier = tmpnam(NULL)) == NULL) {
		perror("tmpnam");
		exit(EXIT_FAILURE);
	}
	if ((fichier = open(nom_fichier, O_RDWR | O_CREAT | O_TRUNC, 0644)) < 0) {
		perror(nom_fichier);
		exit(EXIT_FAILURE);
	}
	if (write(fichier, & fichier, sizeof (int)) != sizeof (int)) {
		perror("write");
		exit(EXIT_FAILURE);
	}
	entier = (int *) mmap(NULL, sizeof (int),
	                      PROT_READ | PROT_WRITE, MAP_SHARED,
	                      fichier, 0);
	if (entier == (int *) MAP_FAILED) {
		perror("mmap");
		exit(EXIT_FAILURE);
	}
	close(fichier);
	unlink(nom_fichier);

	if ((pid = fork()) < 0) {
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0) {
		while (1)
			sleep(1);
	} else {
		for ((* entier) = 0; (* entier) < 10; (* entier) ++) {
			fprintf(stdout, "Pere : * entier = %d\n", * entier);
			fflush(stdout);
			kill(pid, SIGUSR1);
			sleep(1);
		}
		/* Ne pas oublier de tuer le fils qui est en attente */
		kill(pid, SIGKILL);
	}
	return EXIT_SUCCESS;
}

