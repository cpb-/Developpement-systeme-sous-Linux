// ------------------------------------------------------------------
// exemple-opendir.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>

void display_content(const char * directory);

int main (int argc, char * argv[])
{
	int	i;

	if (argc < 2)
		display_content(".");
	else for (i = 1; i < argc; i ++)
		display_content(argv[i]);

	return EXIT_SUCCESS;
}


void display_content (const char * directory)
{
	DIR * dir;
	struct dirent * entry;

	dir = opendir(directory);
	if (dir == NULL)
		return;
	fprintf(stdout, "%s :\n", directory);
	while ((entry = readdir(dir)) != NULL)
		fprintf(stdout, "   %s\n", entry->d_name);
	fprintf(stdout, "\n");
	closedir(dir);
}

