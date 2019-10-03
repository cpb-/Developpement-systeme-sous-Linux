// ------------------------------------------------------------------
// exemple-ioctl-get-values
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2019 Christophe BLAESS - Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <fcntl.h>
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
	int chip_fd;
	struct gpiohandle_request  handle_request;
	struct gpiohandle_data     handle_data;

	chip_fd = open(GPIO_CHIP_NAME, O_RDONLY);
	if (chip_fd < 0) {
		perror(GPIO_CHIP_NAME);
		exit(EXIT_FAILURE);
	}

	memset(&handle_request, 0, sizeof(struct gpiohandle_request));
	handle_request.lineoffsets[0] = GPIO_IN_NUM;
	handle_request.lines = 1;
	handle_request.flags = GPIOHANDLE_REQUEST_INPUT;
	strncpy(handle_request.consumer_label, argv[0], 31);
	if (ioctl(chip_fd, GPIO_GET_LINEHANDLE_IOCTL, &handle_request) != 0) {
		perror("GPIO_GET_LINEHANDLE_IOCTL");
		exit(EXIT_FAILURE);
	}

	for (;;) {
		if (ioctl(handle_request.fd, GPIOHANDLE_GET_LINE_VALUES_IOCTL, &handle_data) != 0) {
			perror("GPIOHANDLE_GET_LINE_VALUES_IOCTL");
			exit(EXIT_FAILURE);
		}
		printf("%d\n", handle_data.values[0]);
	}

	return EXIT_SUCCESS;
}

