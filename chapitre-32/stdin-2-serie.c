// ------------------------------------------------------------------
// stdin-2-serie.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

#define LG_BUFFER    1024

void setspeed (struct termios * config, speed_t vitesse)
{
	cfsetispeed(config, vitesse);
	cfsetospeed(config, vitesse);
}

int main (int argc, char * argv[])
{
	char *  nom_tty           = "/dev/ttyS0";
	int	vitesse           = 9600;
	int	type_parite       = 'n';
	int	nb_bits_donnees   = 8;
	int	nb_bits_arret     = 1;
	int	fd_tty            = -1;
	struct termios configuration;
	struct termios sauvegarde;

	char    buffer[LG_BUFFER];
	int     nb_lus;

	int     option;
	
	opterr = 0;
	while ((option = getopt(argc, argv, "hv:p:d:a:t:")) != -1) {
		switch (option) {
			case 'v' :
				if ((sscanf(optarg, "%d", & vitesse) != 1)
				 || (vitesse < 50) || (vitesse > 115200)) {
					fprintf(stderr, "Vitesse %s invalide \n", optarg);
					exit(EXIT_FAILURE);
				}
				break;
			case 'p' :
				type_parite = optarg[0];
				if ((type_parite != 'n') && (type_parite != 'p')
				 && (type_parite != 'i')) {
					fprintf(stderr, "Parite %c invalide \n", type_parite);
					exit(EXIT_FAILURE);
				}
				break;
			case 'd' :
				if ((sscanf(optarg, "%d", & nb_bits_donnees) != 1)
				 || (nb_bits_donnees < 5) || (nb_bits_donnees > 8)) {
					fprintf(stderr, "Nb bits donnees %d invalide \n",
							nb_bits_donnees);
					exit(EXIT_FAILURE);
				}
				break;
			case 'a' :	
				if ((sscanf(optarg, "%d", & nb_bits_arret) != 1)
				 || (nb_bits_arret < 1) || (nb_bits_arret > 2)) {
					fprintf(stderr, "Nb bits arret %d invalide \n",
							nb_bits_arret);
					exit(EXIT_FAILURE);
				}
				break;
			case 't' :
				nom_tty = optarg;
				break;
			case 'h' :
				fprintf(stderr, "Syntaxe %s [options]... \n", argv [0]);
				fprintf(stderr, "  Options : \n");
				fprintf(stderr, "     -v <vitesse en bits/seconde>  \n");
				fprintf(stderr, "     -p <parite> (n)ulle (p)aire (i)mpaire \n");
				fprintf(stderr, "     -d <bits de donnees> (5 a 8) \n");
				fprintf(stderr, "     -a <bits d'arret> (1 ou 2) \n");
				fprintf(stderr, "     -t <nom du peripherique> \n");
				exit(EXIT_SUCCESS);
			default :
				fprintf (stderr, "Option -h pour avoir de l'aide \n");
				exit(EXIT_FAILURE);
		}
	}
	// Ouverture non-bloquante pour basculer en mode non-local
	fd_tty = open(nom_tty, O_RDWR | O_NONBLOCK);
	if (fd_tty < 0) {
		perror(nom_tty);
		exit(EXIT_FAILURE);
	}
	if (tcgetattr(fd_tty, & configuration) != 0) {
		perror("tcgetattr");
		exit(EXIT_FAILURE);
	}
	configuration.c_cflag	&= ~ CLOCAL;
	tcsetattr(fd_tty, TCSANOW, & configuration);
	// Passage du descripteur en mode bloquant
	fcntl(fd_tty, F_SETFL, fcntl(fd_tty, F_GETFL) & ~O_NONBLOCK);
	fprintf(stderr, "Port serie ouvert \n");
	tcgetattr(fd_tty, & configuration);
	memcpy(& sauvegarde, & configuration, sizeof(struct termios));
	cfmakeraw(& configuration);
	if (vitesse < 50)
		setspeed(& configuration, B50);
	else if (vitesse < 75)
		setspeed(& configuration, B75);
	else if (vitesse < 110)
		setspeed(& configuration, B110);
	else if (vitesse < 134)
		setspeed(& configuration, B134);
	else if (vitesse < 150)
		setspeed(& configuration, B150);
	else if (vitesse < 200)
		setspeed(& configuration, B200);
	else if (vitesse < 300)
		setspeed(& configuration, B300);
	else if (vitesse < 600)
		setspeed(& configuration, B600);
	else if (vitesse < 1200)
		setspeed(& configuration, B1200);
	else if (vitesse < 1800)
		setspeed(& configuration, B1800);
	else if (vitesse < 2400)
		setspeed(& configuration, B2400);
	else if (vitesse < 4800)
		setspeed(& configuration, B4800);
	else if (vitesse < 9600)
		setspeed(& configuration, B9600);
	else if (vitesse < 19200)
		setspeed(& configuration, B19200);
	else if (vitesse < 34000)
		setspeed(& configuration, B38400);
	else if (vitesse < 57600)
		setspeed(& configuration, B57600);
	else 
		setspeed(& configuration, B115200);
	switch (type_parite) {
		case 'n' :
			configuration . c_cflag &= ~ PARENB;
			break;
		case 'p' :
			configuration . c_cflag |=   PARENB;
			configuration . c_cflag &= ~ PARODD;
			break;
		case 'i':
			configuration . c_cflag |=   PARENB;
			configuration . c_cflag |=   PARODD;
			break;
	}
	configuration.c_cflag &= ~ CSIZE;
	if (nb_bits_donnees == 5)
		configuration.c_cflag |= CS5;
	else if (nb_bits_donnees == 6)
		configuration.c_cflag |= CS6;
	else if (nb_bits_donnees == 7)
		configuration.c_cflag |= CS7;
	else if (nb_bits_donnees == 8)
		configuration.c_cflag |= CS8;
	if (nb_bits_arret == 1)
		configuration.c_cflag &= ~ CSTOPB;
	else
		configuration.c_cflag |=   CSTOPB;

	configuration.c_cflag &= ~ CLOCAL;
	configuration.c_cflag |=   HUPCL;
	
	// Controle de flux CTS/RTS specifique Linux
	configuration.c_cflag |=   CRTSCTS;
	
	if (tcsetattr(fd_tty, TCSANOW, & configuration) < 0) {
		perror("tcsetattr");
		exit(EXIT_FAILURE);
	}
	fprintf(stderr, "Port serie configure \n");
		
	fprintf(stderr, "Debut de l'envoi des donnees \n");
	while (1) {
		nb_lus = read(STDIN_FILENO, buffer, LG_BUFFER);
		if (nb_lus < 0)  {
			perror("read");
			exit(EXIT_FAILURE);
		}
		if (nb_lus == 0)
			break;
		write(fd_tty, buffer, nb_lus);
	}
	fprintf(stderr, "Fin de l'envoi des donnees \n");
	sleep(2);
	close(fd_tty);
	// restauration de la configuration originale
	fd_tty = open(nom_tty, O_RDWR | O_NONBLOCK);
	sauvegarde.c_cflag |= CLOCAL;
	tcsetattr(fd_tty, TCSANOW, & sauvegarde);
	close(fd_tty);
	return EXIT_SUCCESS;
}

