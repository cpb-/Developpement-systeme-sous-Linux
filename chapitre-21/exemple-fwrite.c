// ------------------------------------------------------------------
// exemple-fwrite.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	double	x;
	double	y;
	double	z;
} point_t;

int main (void)
{
	point_t * table;
	int       n;
	int       i;
	FILE *    fp;

	n = 8;
	table = calloc(n, sizeof (point_t));
	if (table == NULL) {
		perror("calloc");
		exit(EXIT_FAILURE);
	}

	// Initialisation
	table[0].x = -1.0; table[0].y = -1.0; table[0].z = -1.0;
	table[1].x =  1.0; table[1].y = -1.0; table[1].z = -1.0;
	table[2].x = -1.0; table[2].y =  1.0; table[2].z = -1.0;
	table[3].x =  1.0; table[3].y =  1.0; table[3].z = -1.0;
	table[4].x = -1.0; table[4].y = -1.0; table[4].z =  1.0;
	table[5].x =  1.0; table[5].y = -1.0; table[5].z =  1.0;
	table[6].x = -1.0; table[6].y =  1.0; table[6].z =  1.0;
	table[7].x =  1.0; table[7].y =  1.0; table[7].z =  1.0;

	// Sauvegarde
	if ((fp = fopen("essai.fread", "w")) == NULL) {
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	// Ecriture du nombre de points, suivi de la table
	if ((fwrite(& n, sizeof (int), 1, fp) != 1)
	 || (fwrite(table, sizeof (point_t), 8, fp) != 8)) {
		perror("fwrite");
		exit(EXIT_FAILURE);
	}
	fclose(fp);
	free(table);
	table = NULL;
	n = 0;

	// Recuperation
	if ((fp = fopen("essai.fread", "r")) == NULL) {
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	if (fread(& n, sizeof (int), 1, fp) != 1) {
		perror("fread");
		exit(EXIT_FAILURE);
	}
	if ((table = calloc (n, sizeof (point_t))) == NULL) {
		perror("calloc");
		exit(EXIT_FAILURE);
	}
	if (fread (table, sizeof (point_t), n, fp) != 8) {
		perror ("fread");
		exit(EXIT_FAILURE);
	}
	fclose(fp);

	// Affichage
	for (i = 0; i < n; i ++)
		fprintf(stdout, "point[%d] : % f, % f, % f\n",
			i, table[i].x, table[i].y, table[i].z);

	return EXIT_SUCCESS;
}

