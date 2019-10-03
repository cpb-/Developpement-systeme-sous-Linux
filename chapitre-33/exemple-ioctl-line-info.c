// ------------------------------------------------------------------
// exemple-ioctl-chip-info
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2019 Christophe BLAESS - Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <linux/gpio.h>

#include <sys/ioctl.h>


int filter(const struct dirent * entry)
{
	return strncmp(entry->d_name, "gpiochip", 8) == 0;
}


int display_line_info(int chip_fd, int offset)
{
	struct gpioline_info info;

	memset(&info, 0, sizeof(struct gpioline_info));
	info.line_offset = offset;
	if (ioctl(chip_fd, GPIO_GET_LINEINFO_IOCTL, &info) != 0)
		return -1;
	printf(" %2d: name=%s, consumer=%s, ", offset, info.name, info.consumer);
	if (info.flags & GPIOLINE_FLAG_IS_OUT)
		printf("Out ");
	else
		printf("In  ");
	if (info.flags & GPIOLINE_FLAG_ACTIVE_LOW)
		printf("Active-Low  ");
	else
		printf("Active-High ");
	printf("\n");

	return 0;
}


void display_chip_info(const char *filename)
{
	int fd;
	int offset;
	struct gpiochip_info  info;

	if (chdir("/dev") != 0) {
		perror("/dev");
		return;
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0) {
		perror(filename);
		return;
	}
	memset(&info, 0, sizeof(struct gpiochip_info));
	if (ioctl(fd, GPIO_GET_CHIPINFO_IOCTL, &info) < 0) {
		perror(filename);
		close(fd);
		return;
	}
	printf("/dev/%s: name = %s, label = %s, lines = %d\n",
		filename, info.name, info.label, info.lines);
	for (offset = 0; offset < info.lines; offset++) {
		if (display_line_info(fd, offset) != 0)
			break;
	}
	close(fd);
}


int main (int argc, char * argv[])
{
	struct dirent **chips;
	int    nb_chips;
	int    i;

	nb_chips = scandir("/dev", &chips, filter, alphasort);
	for (i = 0; i < nb_chips; i ++) {
		display_chip_info(chips[i]->d_name);
	}


	return EXIT_SUCCESS;
}

