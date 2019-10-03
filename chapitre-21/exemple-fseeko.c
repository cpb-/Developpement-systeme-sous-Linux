// ------------------------------------------------------------------
// exemple-fseeko.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

// #define _FILE_OFFSET_BITS 64

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[])
{
	int    i;
	FILE * fp;
	int    character;
	int    swap;

	off_t  start;
	off_t  end;

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
		end = ftello(fp) - 1;
		start = 0;
		while (end > start) {
			if (fseeko(fp, end, SEEK_SET) != 0)
				break;
			character = fgetc(fp);
			if (fseeko(fp, start, SEEK_SET) != 0)
				break;
			swap = fgetc(fp);
			if (fseeko(fp, start, SEEK_SET) != 0)
				break;
			fputc(character, fp);
			if (fseeko(fp, end, SEEK_SET) != 0)
				break;
			fputc(swap, fp);
			end --;
			start ++;	
		}
		fclose(fp);
	}
	return EXIT_SUCCESS;
}

