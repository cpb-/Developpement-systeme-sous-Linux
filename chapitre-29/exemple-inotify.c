// ------------------------------------------------------------------
// exemple-inotify.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/inotify.h>


void affiche_evenement(struct inotify_event * event)
{
	if (event->len > 0)
		fprintf(stdout, "%s : ", event->name);
	if (event->mask & IN_ACCESS)
		fprintf(stdout, "acces, ");
	if (event->mask & IN_ATTRIB)
		fprintf(stdout, "modification attributs, ");
	if (event->mask & IN_CLOSE_WRITE)
		fprintf(stdout, "close (read/write), ");
	if (event->mask & IN_CLOSE_NOWRITE)
		fprintf(stdout, "close (read only), ");
	if (event->mask & IN_CREATE)
		fprintf(stdout, "creation, ");
	if (event->mask & IN_DELETE)
		fprintf(stdout, "effacement, ");
	if (event->mask & IN_DELETE_SELF)
		fprintf(stdout, "destruction, ");
	if (event->mask & IN_MODIFY)
		fprintf(stdout, "modification, ");
	if (event->mask & IN_MOVE_SELF)
		fprintf(stdout, "deplacement, ");
	if (event->mask & IN_MOVED_FROM)
		fprintf(stdout, "depart, ");
	if (event->mask & IN_MOVED_TO)
		fprintf(stdout, "arrivee, ");
	if (event->mask & IN_OPEN)
		fprintf(stdout, "ouverture, ");
	fprintf(stdout, "\n");
}

int main(int argc, char * argv[])
{
	int fd;
	struct inotify_event * event;
	event = malloc(sizeof(struct inotify_event) + PATH_MAX);
	if (argc != 2) {
		fprintf(stderr, "usage: %s repertoire\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((fd = inotify_init()) < 0) {
		perror("inotify_init");
		exit(EXIT_FAILURE);
	}
	if (inotify_add_watch(fd, argv[1], IN_ALL_EVENTS) < 0) {
		perror(argv[1]);
		exit(EXIT_FAILURE);

	}
	while (read(fd, event, sizeof(struct inotify_event) + PATH_MAX) > 0) {
		affiche_evenement(event);
	}
	return EXIT_SUCCESS;
}

