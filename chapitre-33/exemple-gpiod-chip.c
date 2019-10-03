// ------------------------------------------------------------------
// exemple-gpiod-chip.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2019 Christophe BLAESS - Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <gpiod.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
	struct gpiod_chip_iter *iter;
	struct gpiod_chip *chip;

	iter = gpiod_chip_iter_new();
	if (iter == NULL) {
		perror("gpiod_chip_iter");
		exit(EXIT_FAILURE);
	}
	while ((chip = gpiod_chip_iter_next(iter)) != NULL)
		fprintf(stdout, "%s - %s - %d lines\n",
		        gpiod_chip_name(chip),
		        gpiod_chip_label(chip),
		        gpiod_chip_num_lines(chip));
	gpiod_chip_iter_free(iter);

	return EXIT_SUCCESS;
}
