// ------------------------------------------------------------------
// exemple-taillles.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

void display_status(struct stat *status)
{
	if (S_ISBLK(status->st_mode))
		fprintf(stderr, "bloc ");
	else if (S_ISCHR(status->st_mode))
		fprintf(stderr, "caractere ");
	else if (S_ISDIR(status->st_mode))
		fprintf(stderr, "repertoire ");
	else if (S_ISFIFO(status->st_mode))
		fprintf(stderr, "fifo ");
	else if (S_ISLNK(status->st_mode))
		fprintf(stderr, "lien ");
	else if (S_ISREG(status->st_mode))
		fprintf(stderr, "fichier ");
	else if (S_ISSOCK(status->st_mode))
		fprintf(stderr, "socket ");
	fprintf(stderr, "%ld", status->st_size);
	fprintf(stderr, "\n");
}	


int main (int argc, char * argv[])
{
	struct stat status;
	int	i;

	if (argc == 1) {
		fprintf(stderr, "stdin : ");
		if (fstat(STDIN_FILENO, & status) < 0)
			perror("");
		else
			display_status(& status);
		fprintf(stderr, "stdout : ");
		if (fstat(STDOUT_FILENO, & status) < 0)
			perror("");
		else
			display_status(& status);
	} else {
		for (i = 1; i < argc ; i ++) {
			fprintf(stderr, "%s : ", argv[i]);
			if (lstat(argv[i], & status) < 0)
				perror("");
			else
				display_status(& status);
		}
	}
	return EXIT_SUCCESS;
}

