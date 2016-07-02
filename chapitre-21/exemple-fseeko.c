// ------------------------------------------------------------------
// exemple-fseeko.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

// #define _FILE_OFFSET_BITS 64
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[])
{
	int    i;
	FILE * fp;
	int    caractere;
	int    echange;

	off_t  debut;
	off_t  fin;

	if (argc < 2) {
		fprintf(stderr, "syntaxe : %s fichier...\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	for (i = 1; i < argc ; i ++) {
		if ((fp = fopen(argv[i], "r+")) == NULL) {
			fprintf(stderr, "%s inaccessible\n", argv[i]);
			continue;
		}
		if (fseeko(fp, 0, SEEK_END) != 0) {
			fprintf(stderr, "%s non positionnable\n", argv[i]);
			fclose(fp);
			continue;
		}
		fin = ftello(fp) - 1;
		debut = 0;
		while (fin > debut) {
			if (fseeko(fp, fin, SEEK_SET) != 0)
				break;
			caractere = fgetc(fp);
			if (fseeko(fp, debut, SEEK_SET) != 0)
				break;
			echange = fgetc(fp);
			if (fseeko(fp, debut, SEEK_SET) != 0)
				break;
			fputc(caractere, fp);
			if (fseeko(fp, fin, SEEK_SET) != 0)
				break;
			fputc(echange, fp);
			fin --;
			debut ++;	
		}
		fclose(fp);
	}
	return EXIT_SUCCESS;
}

