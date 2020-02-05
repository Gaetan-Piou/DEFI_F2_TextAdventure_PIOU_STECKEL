#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined (WIN32)
    #include <winsock2.h>
    typedef int socklen_t;
#elif defined (linux)
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <unistd.h>
    #define INVALID_SOCKET -1
    #define SOCKET_ERROR -1
    #define closesocket(s) close(s)
    typedef int SOCKET;
    typedef struct sockaddr_in SOCKADDR_IN;
    typedef struct sockaddr SOCKADDR;
#endif

#define PORT 23

typedef int socklen_t;

char majuscule(char majuscule);
void passage(char chaine[55]);
void afficheHote();

int main() {
	WSADATA WSAData;
	WSAStartup(MAKEWORD(2,2), &WSAData);

	//Initialisation variables sockets
	SOCKET sock;
	SOCKET servSock;
	SOCKADDR_IN sin;
	SOCKET csock;
	char buffer[64]="";
	SOCKADDR_IN csin;
	socklen_t recsize = sizeof(csin);
	int sock_err;

	int essai,sortie;
	int ordrePorte;
    char posBouton;

	//Tout ce qui est au dessus de ce commentaire est obligatoire

	//Sélection Host/client
	int x;
	do {
		printf("Choisissez 1 pour serveur, 2 pour client : ");
		scanf("%d", &x);
	} while(x != 1 && x != 2);

	//Programme
	if(x == 1) {  /////////////////////// SERVEUR ///////////////////////
		sock = socket(AF_INET, SOCK_STREAM, 0);

		/* Si la socket est valide */
		if(sock != INVALID_SOCKET) {
			printf("La socket %d est maintenant ouverte en mode TCP/IP\n", sock);
            afficheHote();

			/* Configuration */
			sin.sin_addr.s_addr = htonl(INADDR_ANY); /* Adresse IP automatique */
			sin.sin_family = AF_INET; /* Protocole familial (IP) */
			sin.sin_port = htons(PORT); /* Listage du port */
			sock_err = bind(sock, (SOCKADDR*)&sin, sizeof(sin)); //On s'assure que tout fonctionne

			/* Si la socket fonctionne */
			if(sock_err != SOCKET_ERROR) {
				/* Démarrage du listage (mode server) */
				sock_err = listen(sock, 5);

				/* Si la socket fonctionne */
				if(sock_err != SOCKET_ERROR) {

					csock = accept(sock, (SOCKADDR*)&csin, &recsize);

                    Sleep(2000);

					system("cls");

                    printf("Vous etes un mage se servant de ses pouvoirs pour des activites criminelles.\nVous avez recemment ete capture par la garde du pays dans lequel vous commetiez vos exactions et avez ete juge : vous allez etre execute dans 3 jours.\n");
                    printf("Heureusement pour vous, votre complice est la pour vous sortir d'ici, et maintient un lien telepathique avec vous pour que vous puissiez vous entraider\n");
                    printf("Il a deja reussi a s'introduire dans la partie la moins securisee de la prison, mais maintenant, il risque d'avoir besoin de votre aide...\n");

                    fflush(stdin);
                    getchar();

                    //Enigme 1

                    system("cls");

					printf("Enferme dans votre cellule, vous observez les va-et-viens des geoliers en utilisant votre capacite de prediction. \nIl y a trois gardes : le premier est grand et fort, le deuxieme est maigre et le troisieme a l'air energique.\n");
					printf("En meme temps, vous communiquez avec votre camarade pour lui dire quand il devra agir.\n");
					printf("Vous savez pertinement qu'il ne sera capable de vaincre que le plus maigre, et qu'il n'a absolument aucune chance s'il sort de sa cachette alors qu'il y a plus d'un garde la ou il se trouve\n");
    				printf("Vous savez egalement qu'il y a une porte que vous n'etes pas capable de voir plus loin a gauche, qui ne peut laisser passer qu'une personne en meme temps. C'est d'ailleurs derriere cette porte que votre camarade est cache\n");
    				printf("Vous allez devoir compter les passages des gardes et les ouvertures des portes et dire a votre camarade quand attaquer\n");

    				fflush(stdin);
    				getchar();
    				system("cls");

    				passage("Le garde maigre passe devant votre cellule et part vers la gauche. \n");

   					passage("Le garde energique passe a son tour et part vers la gauche. \n");

   					passage("Vous entendez un claquement de porte. \n");

   					passage("Le grand garde passe devant votre cellule et part vers la gauche. \n");

   					passage("Le garde maigre passe a nouveau devant votre cellule et part vers la droite. \n");

   					passage("Le grand garde passe devant votre cellule et part vers la droite. \n");

   					passage("Il ne se passe rien pendant un temps.\n");

   					passage("Le garde maigre repasse devant votre cellule et part vers la gauche. \n");

   					passage("Vous entendez un claquement de porte. \n");

   					passage("Il ne se passe rien pendant un temps.");

   					passage("Vous entendez un autre claquement de porte. \n");

   					passage("Le garde energique repasse devant votre cellule et part vers la droite. \n");

   					passage("Vous entendez un claquement de porte. \n");

   					passage("Le garde maigre repasse devant votre cellule et part vers la droite. \n");

   					passage("Le grand garde passe devant votre cellule et part vers la gauche\n");

   					passage("Vous entendez un claquement de porte. \n");

   					passage("Le garde maigre passe devant votre cellule et part vers la gauche.\n");

   					passage("Vous entendez un claquement de porte. \n");

   					passage("Le garde energique passe devant votre cellule et part vers la gauche.\n");

   					passage("Vous entendez un claquement de porte. \n");

   					passage("Le grand garde passe devant votre cellule et part vers la droite.\n");

   					passage("Le garde maigre passe devant votre cellule et part vers la droite.\n");

   					passage("Vous entendez un claquement de porte. \n");

   					passage("Le garde energique passe devant votre cellule et part vers la droite.\n");

   					if(send(csock, "Epreuve 1", sizeof(buffer), 0) != SOCKET_ERROR) {
   						printf("Votre prediction prend fin, utilisez votre lien telepathique pour communiquer avec votre camarade\n");
   					}


					//Enigme 2

					if(recv(csock, buffer, sizeof(buffer), 0) != SOCKET_ERROR) {
						if(buffer[0] == 'R') {
							if(send(csock, "Epreuve 2", sizeof(buffer), 0) != SOCKET_ERROR) {
								printf("Il y a un texte sur le mur : \nA l'oree des bois je me tiens, me balancant legerement a chaque bourrasque. \nPersonne n'ose me regarder car du silence je suis le monarque. \n");
							}
		
							if(recv(csock, buffer, sizeof(buffer), 0) != SOCKET_ERROR) {
								if(buffer[0] == 'R') {
									printf("Vous entendez un cliquetis, la porte de votre cellule s'ouvre et vous etes libre ! Bravo !\n");
								} else {
									printf("Votre camarade a ete capture et mis dans la meme cellule que vous, vous ne pourrez plus sortir\n");
								}
							}
						} else {
							printf("Votre camarade a ete capture et mis dans la meme cellule que vous, vous ne pourrez plus sortir\n");
						}
					}

					fflush(stdin);
					getchar();

					shutdown(csock, 2);

					/* Il ne faut pas oublier de fermer la connexion (fermée dans les deux sens) */
				}
			}

			/* Fermeture de la socket */
			printf("Fermeture de la socket...\n");
			closesocket(sock);
			printf("Fermeture du serveur terminee\n");
		}
	} else if(x == 2) {  /////////////////////// CLIENT ///////////////////////
		servSock = socket(AF_INET, SOCK_STREAM, 0);

		/* Création de la socket */
		sock = socket(AF_INET, SOCK_STREAM, 0);

        char cIP[15]={'\0'};
        printf("Veuillez rentrer l'adresse IP de l'hote.\n");
        fflush(stdin);
        fgets(cIP,sizeof(cIP),stdin);
        fflush(stdin);

		/* Configuration de la connexion */
		sin.sin_addr.s_addr = inet_addr(cIP);
		sin.sin_family = AF_INET;
		sin.sin_port = htons(PORT);

		/* Si l'on a réussi à se connecter */
		if(connect(sock, (SOCKADDR*)&sin, sizeof(sin)) != SOCKET_ERROR)
		{
			printf("Connection à %s sur le port %d\n", inet_ntoa(sin.sin_addr), htons(sin.sin_port));
            Sleep(2000);

            system("cls");


            printf("Vous etes un mage se servant de ses pouvoirs pour des activites criminelles.\nIl y a peu de temps, votre complice a ete capture par la garde du pays dans lequel vous commetiez vos exactions et a ete juge : il sera execute dans 3 jours\n");
            printf("Vous avez alors decide de le sortir de prison coute que coute\nVous avez reussi a penetrer la partie la moins importante de la prison sans la moindre difficulte. Mais la suite risque d'etre plus difficile, vous avez heureusement votre complice enferme qui tient un lien telepathique avec vous pour vous conseiller...");

            fflush(stdin);
            getchar();

            system("cls");

			printf("Vous attendez cache derriere une porte grace a votre pouvoir de camouflage, attendant les informations de votre camarade par votre lien telepathique\n");

			if(recv(sock, buffer, sizeof(buffer), 0) != SOCKET_ERROR) {
				//Joueur 1
				essai = 0;
				sortie = 1;


   				while(essai < 2 && sortie == 1) {
   					printf("Apres quel claquement de porte decidez-vous d'attaquer (entre 1 et 8) ?");
   					scanf("%d",&ordrePorte);

   					switch(ordrePorte) {

   					    case 1:
   					    case 7:
   					        printf("Vous sautez droit vers le geolier. \n");
   					        printf("A votre surprise, votre cible vous esquive et vous maitrise.\n");
   					        essai = 2;
   					        break;
   					    case 2:
   					        printf("Vous sautez droit vers le geolier. \n");
   					        printf("A votre surprise, il y avait deux personne qui n'ont aucun mal a vous maitriser.\n");
   					        essai = 2;
   					        break;
   					    case 5:
   					        printf("Vous sautez droit vers le geolier. \n");
   					        printf("A votre surprise, votre cible vous attrape et vous assome.\n");
   					        essai = 2;
   					        break;
   					    case 3:
   					        printf("Vous sautez droit vers le geolier. \n");
   					        printf("Vous n'avez nul mal a le maitriser. Vous avancez vers le tableau d'ouverture des portes des cellules.\n");
   					        sortie = 0;
   					        break;
   					    case 4:
   					    case 6:
   					    case 8:
   					    	printf("Vous sautez droit vers le geolier. \n");
   					    	if(essai < 1) {
   					    		printf("A votre suprise, il n'y a personne, vous pouvez reessayer.\n");
   					    		essai++;
   					    	} else {
   					    		printf("A votre surprise, il n'y a personne, mais vous attirez l'attention et les trois gardes viennent vous maitriser.\n");
   					    		essai++;
   					    	}
   					    	break;
   					}
   				}
			}


			if(essai < 2) {
				if(send(sock, "R", sizeof(buffer), 0) != SOCKET_ERROR) {

				}
				if(recv(sock, buffer, sizeof(buffer), 0) != SOCKET_ERROR) {
					system("cls");
					essai = 0;
					sortie = 1;
					while(essai < 2 && sortie == 1) {
        				system("cls");
        				printf("Vous vous trouvez devant le tableau.\nIl y a trois boutons. \nCelui de gauche represente un arbre \nCelui du milieu represente un pendu \nCelui de droite represente un drapeau \n");
        				printf("Sur lequel appuyez-vous ?\nG: Le bouton de gauche, avec l'arbre\nM: Le bouton du milieu, avec le pendu\nD: Le bouton de droite, avec le drapeau\n");
        				fflush(stdin);

        				scanf("%c",&posBouton);
        				posBouton = majuscule(posBouton);

        				while(posBouton!='G' && posBouton!='M' && posBouton!='D') {
        				    printf("ERREUR ! Veuillez entrer G, M ou D\n");
        				    printf("\nVous vous trouvez devant une porte scellee, son mecanisme est bloque. \nIl y a trois boutons. \nCelui de gauche represente un arbre \nCelui du 		milieu represente un pendu \nCelui de droite represente un drapeau \n");
        				    printf("Sur lequel appuyez-vous ?\nG: Le bouton de gauche, avec l'arbre\nM: Le bouton du milieu, avec le pendu\nD: Le bouton de droite, avec le drapeau");

        				    fflush(stdin);
        				    posBouton = majuscule(getchar());
        				}

        				switch(posBouton) {
        				case 'G':
        				case 'D':
        				    if(essai==1) {
        				        printf("Vous entendez un bruit aigu pendant quelques secondes, puis plus rien.\n");
        				    } else {
        				        printf("Vous entendez un cliquetis. \nVous avez le sentiment qu'il ne faudra pas echouer une seconde fois. \n");
        				    }
        				    essai++;
        				    break;
        				case 'M':
        				    printf("Vous entendez un cliquetis, puis un autre.\n");
        				    sortie--;
        				    break;
        				}

        				fflush(stdin);
        				getchar();
    				}

    				if(essai < 2) {
    					if(send(sock, "R", sizeof(buffer), 0) != SOCKET_ERROR) {
    						printf("Vous avez reussi a liberer votre camarade ! Bravo !\n");
    					} else {
    						printf("Erreur !\n");
    					}
    				} else {
    					if(send(sock, "E", sizeof(buffer), 0) != SOCKET_ERROR) {
    						printf("Les gardes, alertes par le bruit viennent, vous capturent et vous jettent dans la meme cellule que votre camarade\n");
    					} else {
    						printf("Erreur !\n");
    					}
    				}

				}
			} else {
				printf("Vous etes jete dans la meme cellule que votre camarade\n");
			}

		} else { /* sinon, on affiche "Impossible de se connecter" */
			printf("Impossible de se connecter\n");
		}

		/* On ferme la socket */
		closesocket(sock);
	}

	WSACleanup();

	/* On attend que l'utilisateur tape sur une touche, puis on ferme */
	fflush(stdin);
	getchar();

	return EXIT_SUCCESS;
}


char majuscule(char caractere) {
    if (caractere  >= 'a' &&  caractere <= 'z') {
        caractere -=  'a' - 'A';
    }

    return caractere;
}


void passage(char chaine[55]) {
    printf(chaine);
    Sleep(2500);
    system("cls");
}

void afficheHote() {
    char hostname[1024];
    hostname[1023] = '\0';
    gethostname(hostname, 1023);
    struct hostent* remoteHost;
    remoteHost = gethostbyname(hostname);
    char* ip;
    ip = inet_ntoa(*(struct in_addr *)*remoteHost->h_addr_list);
    printf("Votre adresse IP est : %s.\n", ip);
}