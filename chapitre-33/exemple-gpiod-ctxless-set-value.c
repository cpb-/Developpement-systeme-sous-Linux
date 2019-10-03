// ------------------------------------------------------------------
// exemple-gpiod-ctxless-set-value.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2019 Christophe BLAESS - Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <gpiod.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define GPIO_CHIP_NAME  "/dev/gpiochip0"
#define GPIO_OUT_NUM    24


void waiting_cb(void *arg)
{
	long delay = (long) arg;
	usleep(delay);
}


int main(int argc, char *argv[])
{
	int value = 0;

	for (;;) {
		gpiod_ctxless_set_value(GPIO_CHIP_NAME, GPIO_OUT_NUM, value, 0, argv[0], waiting_cb, (void *)500000);
		value = 1 - value;
	}
	return EXIT_SUCCESS;
}
