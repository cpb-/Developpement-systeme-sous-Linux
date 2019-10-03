// ------------------------------------------------------------------
// exemple-setitimer-2.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void function_to_profile(void);

int main (void)
{
	function_to_profile();
	return EXIT_SUCCESS;
}

void function_to_profile(void)
{
	int i, j;
	FILE * fp1, * fp2;
	double x = 0.0;

	for (i = 0; i < 30000; i ++)
		for (j = 0; j < 30000; j ++)
			x += i * j;
	for (i = 0; i < 50000; i ++) {
		if ((fp1 = fopen ("exemple_setitimer_2", "r")) != NULL) {
			if ((fp2 = fopen("/dev/null", "w")) != NULL) {
				while (fread(& j, sizeof (int), 1, fp1) == 1)
					fwrite(& j, sizeof (int), 1, fp2);
				fclose(fp2);
			}
			fclose(fp1);
		}
	}
}


