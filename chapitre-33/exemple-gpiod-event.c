// ------------------------------------------------------------------
// exemple-gpiod-event.c
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

int main(int argc, char *argv[])
{
	struct gpiod_chip *chip;
	struct gpiod_line *line;
	struct gpiod_line_event evt;

	chip = gpiod_chip_open_lookup(GPIO_CHIP_NAME);
	if (chip == NULL) {
		perror(GPIO_CHIP_NAME);
		exit(EXIT_FAILURE);
	}

	line  = gpiod_chip_get_line(chip, GPIO_IN_NUM);

	if (line == NULL) {
		fprintf(stderr, "%s: invalid GPIO number.\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if (gpiod_line_is_used(line)) {
		fprintf(stderr, "%s: GPIO %d busy.\n", argv[0], GPIO_IN_NUM);
		exit(EXIT_FAILURE);
	}
	if (gpiod_line_request_both_edges_events(line, argv[0]) < 0) {
		fprintf(stderr, "%s: can't wait on GPIO %d.\n", argv[0], GPIO_IN_NUM);
                exit(EXIT_FAILURE);
        }

	for (;;) {
		if (gpiod_line_event_wait(line, NULL) != 1)
			break;
		if (gpiod_line_event_read(line, &evt) != 0)
			break;
		printf("[%ld.%09ld] ",
		         evt.ts.tv_sec, evt.ts.tv_nsec);
		if (evt.event_type == GPIOD_LINE_EVENT_RISING_EDGE)
			printf("Rising\n");
		else
			printf("Falling\n");

	}
	gpiod_line_release(line);
	gpiod_chip_close(chip);

	return EXIT_SUCCESS;
}
