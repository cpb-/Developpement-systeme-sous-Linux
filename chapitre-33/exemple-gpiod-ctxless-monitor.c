// ------------------------------------------------------------------
// exemple-gpiod-ctxless-monitor.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2019 Christophe BLAESS - Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <gpiod.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define GPIO_CHIP_NAME  "/dev/gpiochip0"
#define GPIO_IN_NUM     23


int monitor_cb(int evt_type, unsigned int offset,
                const struct timespec *ts,
                void *unused)
{
	printf("[%ld.%09ld] %d ", ts->tv_sec, ts->tv_nsec, offset);
	if (evt_type == GPIOD_CTXLESS_EVENT_CB_RISING_EDGE)
		printf("Rising");
	if (evt_type == GPIOD_CTXLESS_EVENT_CB_FALLING_EDGE)
		printf("Falling");
	printf("\n");
	return GPIOD_CTXLESS_EVENT_CB_RET_OK;
}



int main(int argc, char *argv[])
{
	gpiod_ctxless_event_monitor(GPIO_CHIP_NAME,
	                            GPIOD_CTXLESS_EVENT_BOTH_EDGES,
	                            GPIO_IN_NUM,
	                            0,
	                            argv[0],
	                            NULL,
	                            NULL,
	                            monitor_cb,
	                            NULL);
	return EXIT_SUCCESS;
}
