// ------------------------------------------------------------------
// exemple-on-exit.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

void exit_handling(int code, void *pointer);

int main (void)
{
	FILE *fp;

	fp = fopen("exemple-atexit.c", "r");
	if (on_exit(exit_handling, (void *)fp) != 0)
		fprintf(stderr, "Error during on_exit()\n");

	fp = fopen("exemple-on-exit.c", "r");
	if (on_exit(exit_handling, (void *)fp) != 0)
		fprintf(stderr, "Error during on_exit()\n");

	if (on_exit(exit_handling, NULL) != 0)
		fprintf(stderr, "Error during on_exit\n");

	fprintf(stdout, "Ok, returning from main()\n");
	return 4;
}

void exit_handling(int code, void *pointer)
{
	fprintf(stdout, "exit_handling() called... code %d\n", code);
	if (pointer == NULL) {
		fprintf(stdout, "No file to close\n");
	} else {
		fprintf(stdout, "Closing file\n");
		fclose((FILE *)pointer);
	}
}

