// ------------------------------------------------------------------
// exemple-gpiod-ctxless-get-value.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2019 Christophe BLAESS - Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <gpiod.h>
#include <stdio.h>
#include <stdlib.h>

#define GPIO_CHIP_NAME  "/dev/gpiochip0"
#define GPIO_IN_NUM    23

int main(int argc, char *argv[])
{
	int value;

	value = gpiod_ctxless_get_value(GPIO_CHIP_NAME, GPIO_IN_NUM, 0, argv[0]);

	if (value < 0) {
		perror("gpiod_ctxless_get_value");
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", value);
	return EXIT_SUCCESS;
}
