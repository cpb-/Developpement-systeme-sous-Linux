// ------------------------------------------------------------------
// exemple-chroot.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char * argv[])
{
	if (argc < 3) {
		fprintf(stderr, "Syntaxe %s chemin commande...\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if (chdir (argv [1]) != 0){
		perror("chdir");
		exit(EXIT_FAILURE);
	}
	if (chroot(argv[1]) != 0) {
		perror("chroot");
		exit(EXIT_FAILURE);
	}
	if (seteuid(getuid()) < 0) {
		perror("seteuid");
		exit(EXIT_FAILURE);
	}
	execvp(argv[2], argv + 2);
	perror("execvp");
	return EXIT_FAILURE;
}

