SHELL=/bin/sh

CFLAGS = -Wall -g


EXECUTABLES=                         \
           exemple-ioctl-chip-info   \
           exemple-ioctl-line-info   \
           exemple-ioctl-set-values  \
           exemple-ioctl-get-values  \
           exemple-ioctl-poll        \


GPIOD_EXECUTABLES =                         \
           exemple-gpiod-ctxless-get-value  \
           exemple-gpiod-ctxless-set-value  \
           exemple-gpiod-ctxless-monitor    \
           exemple-gpiod-ctxless-monitor-set-value \
           exemple-gpiod-chip               \
           exemple-gpiod-line               \
           exemple-gpiod-get-set-value      \
           exemple-gpiod-event              \


all : ${EXECUTABLES}


gpiod: $(GPIOD_EXECUTABLES)


exemple-gpiod-ctxless-get-value: exemple-gpiod-ctxless-get-value.c
	$(CC) $(CFLAGS) -lgpiod -o $@ $<

exemple-gpiod-ctxless-set-value: exemple-gpiod-ctxless-set-value.c
	$(CC) $(CFLAGS) -lgpiod -o $@ $<

exemple-gpiod-ctxless-monitor: exemple-gpiod-ctxless-monitor.c
	$(CC) $(CFLAGS) -lgpiod -o $@ $<

exemple-gpiod-ctxless-monitor-set-value: exemple-gpiod-ctxless-monitor-set-value.c
	$(CC) $(CFLAGS) -lgpiod -pthread -o $@ $<

exemple-gpiod-chip: exemple-gpiod-chip.c
	$(CC) $(CFLAGS) -lgpiod -o $@ $<

exemple-gpiod-line: exemple-gpiod-line.c
	$(CC) $(CFLAGS) -lgpiod -o $@ $<

exemple-gpiod-get-set-value: exemple-gpiod-get-set-value.c
	$(CC) $(CFLAGS) -lgpiod -o $@ $<

exemple-gpiod-event: exemple-gpiod-event.c
	$(CC) $(CFLAGS) -lgpiod -o $@ $<

clean:
	@rm -f core* *.o *.out *~
	@rm -f $(EXECUTABLES) $(GPIOD_EXECUTABLES)
