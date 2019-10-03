// ------------------------------------------------------------------
// exemple-epoll.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/epoll.h>

#define	CHILDS	10

int main (void)
{
	int pipe_fd[CHILDS][2];
	int i;
	int n;
	char c;
	int efd;
	struct epoll_event evt;
	struct epoll_event * revts = NULL;

	for (i = 0; i < CHILDS; i ++) {
		if (pipe (pipe_fd[i]) < 0) {
			perror("pipe");
			exit(EXIT_FAILURE);
		}
		if (fork() == 0) {
			// Enfant
			close(pipe_fd[i][0]);
			c = '0' + i;
			while(1) {
				sleep(i + 1);
				write(pipe_fd[i][1], & c, 1);
			}
		}
		close(pipe_fd[i][1]);
	}

	// Parent
	while (1) {
		efd = epoll_create(CHILDS);
		if (efd < 0) {
			perror("epoll_create");
			exit(EXIT_FAILURE);
		}
		
		for (i = 0; i < CHILDS; i ++) {
			evt.events = EPOLLIN;
			evt.data.fd = pipe_fd[i][0];
			if (epoll_ctl(efd, EPOLL_CTL_ADD, evt.data.fd, & evt) != 0) {
				perror("epoll_ctl");
				exit(EXIT_FAILURE);
			}
		}
		revts = calloc(CHILDS, sizeof(struct epoll_event));
		if (revts == NULL) {
			perror("calloc");
			exit(EXIT_FAILURE);
		}
		n = epoll_wait(efd, revts, CHILDS, -1);
		if (n < 0)
			break;
		for (i = 0; i < n; i ++) {
				read(revts[i].data.fd, & c, 1);
				fprintf(stderr, "%c ", c);
		}
	}
	return EXIT_SUCCESS;
}

