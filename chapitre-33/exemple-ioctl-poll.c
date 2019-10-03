// ------------------------------------------------------------------
// exemple-ioctl-get-values
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2019 Christophe BLAESS - Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <fcntl.h>
#include <poll.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <linux/gpio.h>

#include <sys/ioctl.h>

#define GPIO_CHIP_NAME  "/dev/gpiochip0"
#define GPIO_IN_NUM    23

int main (int argc, char * argv[])
{
	int nb;
	int chip_fd;
	struct pollfd poll_fd;
	struct gpioevent_request  event_request;
	struct gpioevent_data     event_data;

	chip_fd = open(GPIO_CHIP_NAME, O_RDONLY);
	if (chip_fd < 0) {
		perror(GPIO_CHIP_NAME);
		exit(EXIT_FAILURE);
	}

	memset(&event_request, 0, sizeof(struct gpioevent_request));
	event_request.lineoffset  = GPIO_IN_NUM;
	event_request.handleflags = GPIOHANDLE_REQUEST_INPUT;
	event_request.eventflags  = GPIOEVENT_REQUEST_BOTH_EDGES;
	strncpy(event_request.consumer_label, argv[0], 31);
	if (ioctl(chip_fd, GPIO_GET_LINEEVENT_IOCTL, &event_request) != 0) {
		perror("GPIO_GET_LINEEVENT_IOCTL");
		exit(EXIT_FAILURE);
	}

	for (;;) {
		poll_fd.fd = event_request.fd;
		poll_fd.events = POLLIN | POLLPRI;
		nb = poll(&poll_fd, 1, -1);
		if (nb < 0)
			break;
		if (nb > 0) {
			if (read(event_request.fd, &event_data, sizeof(struct gpioevent_data)) > 0) {
				printf("[%llu] ", event_data.timestamp);
				if (event_data.id & GPIOEVENT_EVENT_RISING_EDGE)
					printf("RISING ");
				if (event_data.id & GPIOEVENT_EVENT_FALLING_EDGE)
					printf("FALLING ");
				printf("\n");
			}
		}
	}

	return EXIT_SUCCESS;
}

