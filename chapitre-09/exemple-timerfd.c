#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/timerfd.h>


int main(void)
{
	int fd;
	unsigned long long  overrun;
	struct itimerspec spec;

	fd = timerfd_create(CLOCK_REALTIME, 0);
	if (fd < 0) {
		perror("timerfd_create");
		exit(EXIT_FAILURE);
	}

	spec.it_interval.tv_sec  = 0;
	spec.it_interval.tv_nsec = 100000000; // 1/10 sec.
	spec.it_value = spec.it_interval;

	if (timerfd_settime(fd, 0, &spec, NULL)) {
		perror("timerfd_settime");
		exit(EXIT_FAILURE);
	}

	for (;;) {
		if (read(fd, &overrun, sizeof(overrun)) < 0)
			break;
		fprintf(stderr, "%lld ", overrun);
	}
	return 0;
}


