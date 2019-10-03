// ------------------------------------------------------------------
// exemple-gpiod-line.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2019 Christophe BLAESS - Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <gpiod.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
	struct gpiod_chip *chip;
	int offset;
	struct gpiod_line *line;

	if (argc < 2) {
		fprintf(stderr, "usage: %s gpiochip\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	chip = gpiod_chip_open_lookup(argv[1]);
	if (chip == NULL) {
		perror(argv[1]);
		exit(EXIT_FAILURE);
	}
	for (offset = 0; offset < gpiod_chip_num_lines(chip); offset++) {
		line = gpiod_chip_get_line(chip, offset);
		if ((line == NULL) || (! gpiod_line_is_used(line)))
			continue;
		printf("%2d: ", offset);
		if (gpiod_line_name(line) != NULL)
			printf("%s ", gpiod_line_name(line));
		if (gpiod_line_consumer(line) != NULL)
			printf ("(%s) ", gpiod_line_consumer(line));
		if (gpiod_line_direction(line) == GPIOD_LINE_DIRECTION_INPUT)
			printf ("IN ");
		if (gpiod_line_direction(line) == GPIOD_LINE_DIRECTION_OUTPUT)
			printf ("OUT ");
		printf("\n");
	}
	gpiod_chip_close(chip);

	return EXIT_SUCCESS;
}
