// ------------------------------------------------------------------
// exemple-opendir.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>

void	affiche_contenu (const char * repertoire);

int main (int argc, char * argv[])
{
	int	i;
	if (argc < 2)
		affiche_contenu(".");
	else for (i = 1; i < argc; i ++)
		affiche_contenu(argv[i]);

	return EXIT_SUCCESS;
}

void affiche_contenu (const char * repertoire)
{
	DIR * dir;
	struct dirent * entree;

	dir = opendir(repertoire);
	if (dir == NULL)
		return;
	fprintf(stdout, "%s :\n", repertoire);
	while ((entree = readdir(dir)) != NULL)
		fprintf(stdout, "   %s\n", entree->d_name);
	fprintf(stdout, "\n");
	closedir(dir);
}

