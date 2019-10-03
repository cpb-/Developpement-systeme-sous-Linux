// ------------------------------------------------------------------
// exemple-gpiod-ctxless-monitor-set-value.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2019 Christophe BLAESS - Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <gpiod.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define GPIO_CHIP_NAME  "/dev/gpiochip0"
#define GPIO_IN_NUM      23
#define GPIO_OUT_NUM     24

pthread_mutex_t Gpio_mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  Gpio_cnd = PTHREAD_COND_INITIALIZER;

int monitor_cb(int evt_type, unsigned int offset,
                const struct timespec *ts,
                void *unused)
{
	pthread_mutex_lock(&Gpio_mtx);
	pthread_cond_signal(&Gpio_cnd);
	pthread_mutex_unlock(&Gpio_mtx);
	return GPIOD_CTXLESS_EVENT_CB_RET_OK;
}


void set_gpio_cb(void *unused)
{
        pthread_cond_wait(&Gpio_cnd, &Gpio_mtx);
}


void *set_gpio_thread(void *consumer)
{
	int value = 0;

	pthread_mutex_lock(&Gpio_mtx);
	for (;;) {
		gpiod_ctxless_set_value(GPIO_CHIP_NAME, GPIO_OUT_NUM,
		                        value, 0, consumer,
		                        set_gpio_cb, NULL);
		value = 1 - value;
	}
	pthread_mutex_unlock(&Gpio_mtx);
}


int main(int argc, char *argv[])
{
	pthread_t thr;

	if (pthread_create(&thr, NULL, set_gpio_thread, argv[0]) != 0) {
		fprintf(stderr, "%s: unable to start a thread.\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	gpiod_ctxless_event_monitor(GPIO_CHIP_NAME,
	                            GPIOD_CTXLESS_EVENT_RISING_EDGE,
	                            GPIO_IN_NUM,
	                            0,
	                            argv[0],
	                            NULL,
	                            NULL,
	                            monitor_cb,
	                            NULL);
	return EXIT_SUCCESS;
}

