// ------------------------------------------------------------------
// exemple-mprotect-1.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

#define STRING_SIZE 128


void * my_malloc_with_mmap(size_t size)
{
	void *ret;

	ret = mmap(NULL, size, PROT_READ | PROT_WRITE, 
	              MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
	if (ret == MAP_FAILED)
		return NULL;
	return ret;
}

int main (void)
{
	char *string = NULL;

	fprintf(stdout, "Allocation de %d octets\n", STRING_SIZE);
	string = my_malloc_with_mmap(STRING_SIZE);
	if (string == NULL) {
		perror("mmap");
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "Protections par defaut\n");
	fprintf(stdout, "   Ecriture ...");
	strcpy(string, "Ok");
	fprintf(stdout, "Ok\n");
	fprintf(stdout, "   Lecture ...");
	fprintf(stdout, "%s\n", string);

	fprintf(stdout, "Interdiction d'ecriture\n");
	if (mprotect(string, STRING_SIZE, PROT_READ) < 0) {
		perror("mprotect");
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "   Lecture ...");
	fprintf(stdout, "%s\n", string);
	fprintf(stdout, "   Ecriture ...");
	strcpy(string, "Non");
	/* ici on doit deja etre arrete par un signal */
	return EXIT_SUCCESS;
}

