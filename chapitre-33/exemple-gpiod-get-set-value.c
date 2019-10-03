// ------------------------------------------------------------------
// exemple-gpiod-get-set-value.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2019 Christophe BLAESS - Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <gpiod.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define GPIO_CHIP_NAME  "/dev/gpiochip0"
#define GPIO_IN_NUM      23
#define GPIO_OUT_NUM     24

int main(int argc, char *argv[])
{
	struct gpiod_chip *chip;
	struct gpiod_line *line_in;
	struct gpiod_line *line_out;

	chip = gpiod_chip_open_lookup(GPIO_CHIP_NAME);
	if (chip == NULL) {
		perror(GPIO_CHIP_NAME);
		exit(EXIT_FAILURE);
	}

	line_in  = gpiod_chip_get_line(chip, GPIO_IN_NUM);
	line_out = gpiod_chip_get_line(chip, GPIO_OUT_NUM);

	if ((line_in == NULL) || (line_out == NULL)) {
		fprintf(stderr, "%s: invalid GPIO number.\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if (gpiod_line_is_used(line_in)) {
		fprintf(stderr, "%s: GPIO %d busy.\n", argv[0], GPIO_IN_NUM);
		exit(EXIT_FAILURE);
	}
	if (gpiod_line_is_used(line_out)) {
		fprintf(stderr, "%s: GPIO %d busy.\n", argv[0], GPIO_OUT_NUM);
		exit(EXIT_FAILURE);
	}

	gpiod_line_request_input(line_in, argv[0]);
	gpiod_line_request_output(line_out, argv[0], 0);

	for (;;) {
		gpiod_line_set_value(line_out,
		              1 - gpiod_line_get_value(line_in));
		usleep(1000);
	}
	gpiod_line_release(line_out);
	gpiod_line_release(line_in);
	gpiod_chip_close(chip);

	return EXIT_SUCCESS;
}
