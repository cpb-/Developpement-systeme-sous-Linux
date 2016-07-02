// ------------------------------------------------------------------
// exemple-fchdir.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

void affiche_chemin_courant (void)
{
	char * chemin = NULL;
	char * nouveau = NULL;
	int    taille = 16;

	while (1) {	
		if ((nouveau = realloc(chemin, taille)) == NULL) {
			perror("realloc");
			break;
		}
		chemin = nouveau;
		if (getcwd(chemin, taille) != NULL) {
			fprintf(stdout, "%s\n", chemin);
			break;
		}
		if (errno != ERANGE) {
			perror("getcwd");
			break;
		}
		taille *= 2;
	}
	if (chemin != NULL)
		free(chemin);
}

void change_chemin_courant(const char * nom)
{
	int  fd;
	if ((fd = open(nom, O_RDONLY)) < 0) {
		perror(nom);
		return ;
	}
	if (fchdir(fd) < 0)
		perror(nom);
	close(fd);
}

int main (int argc, char * argv[])
{
	int i;
	
	affiche_chemin_courant();
	for (i = 1; i < argc; i++) {
		change_chemin_courant(argv[i]);
		affiche_chemin_courant();
	}
	return EXIT_SUCCESS;
}
