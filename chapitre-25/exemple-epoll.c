// ------------------------------------------------------------------
// exemple-epoll.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2016 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/epoll.h>

#define	NB_FILS	10

int main (void)
{
	int tube[NB_FILS][2];
	int i;
	int n;
	char c;
	int efd;
	struct epoll_event evt;
	struct epoll_event * revts = NULL;

	for (i = 0; i < NB_FILS; i ++) {
		if (pipe (tube[i]) < 0) {
			perror("pipe");
			exit(EXIT_FAILURE);
		}
		if (fork() == 0) {
			// Fils
			close(tube[i][0]);
			c = '0' + i;
			while(1) {
				sleep(i + 1);
				write(tube[i][1], & c, 1);
			}
		}
		close(tube[i][1]);
	}

	// Père
	while (1) {
		efd = epoll_create(NB_FILS);
		if (efd < 0) {
			perror("epoll_create");
			exit(EXIT_FAILURE);
		}
		
		for (i = 0; i < NB_FILS; i ++) {
			evt.events = EPOLLIN;
			evt.data.fd = tube[i][0];
			if (epoll_ctl(efd, EPOLL_CTL_ADD, evt.data.fd, & evt) != 0) {
				perror("epoll_ctl");
				exit(EXIT_FAILURE);
			}
		}
		revts = calloc(NB_FILS, sizeof(struct epoll_event));
		if (revts == NULL) {
			perror("calloc");
			exit(EXIT_FAILURE);
		}
		n = epoll_wait(efd, revts, NB_FILS, -1);
		if (n < 0)
			break;
		for (i = 0; i < n; i ++) {
				read(revts[i].data.fd, & c, 1);
				fprintf(stderr, "%c ", c);
		}
	}
	return EXIT_SUCCESS;
}

