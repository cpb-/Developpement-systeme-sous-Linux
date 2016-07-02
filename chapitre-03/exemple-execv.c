// ------------------------------------------------------------------
// exemple-execv.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main (int argc, char * argv[])
{
	int fd;

	char * nv_argv[] = { "./exemple-execvp", (char *) NULL };

 	fprintf(stdout, "Essai d'ouverture de %s\n", argv[0]);
	if ((fd = open(argv[0], O_WRONLY | O_APPEND)) < 0) {
		if (errno != ETXTBSY) {
			fprintf(stdout, "  impossible, errno %d\n", errno);
			exit(1);
		}
		fprintf(stdout, "  echec ETXTBSY, fichier deja utilise \n");
	}

	fprintf(stdout, "Ouverture exemple-execvp en ecriture \n");

	if ((fd = open("exemple-execvp", O_WRONLY | O_APPEND)) < 0) {
		fprintf(stdout, "  impossible, errno %d\n", errno);
		exit(1);
	}

	fprintf(stdout, "  Ok\n");
	fprintf(stdout, "Essai d'executer exemple-execvp\n");
	execv("./exemple-execvp", nv_argv);

	if (errno == ETXTBSY)
		fprintf(stdout, "  echec ETXTBSY fichier deja utilise\n");
	else
		fprintf(stdout, "  errno = %d\n", errno);
	return 1;
}
