#ifndef CONSTANTES_H
#define CONSTANTES_H

	#define FIFRANCAIS "Francais.txt"
	#define FIENGLISH "English.txt"

	#define TPSEUDO		30
	#define TNOM		30

	#define NBMAXPERSO 3
	#define NBMAXCHOIXMENU 100

	#define OUI	1
	#define NON 2

	#define PAUSE printf("\n"); system("pause")
	#define CLEAR system("cls")
	#define FF while(getchar() != '\n')
	#define ENTER printf("\n")
	#define TAB printf("\t")

	typedef enum codeErreur CodeErreur;
	enum codeErreur {
		PAS_D_ERREUR,
		//Erreurs logiques...
		MAUVAIS_CHOIX,
		JOUEUR_ABSENT,
		JOUEUR_DEJA_PRESENT,
		PERSONNAGE_ABSENT,
		PERSONNAGE_DEJA_PRESENT,
		POINTS_NON_VALIDES,
		PSEUDO_NON_VALIDE,
		NOM_NON_VALIDE,
		REPONSE_NON_VALIDE,
		NB_MAX_PERSO_ATTEINT,
		FICHIER_VIDE,
		//Erreurs système...
		ERREUR_SYSTEME = 100,
		FICHIER_INEXISTANT,
		ALLOCATION_MEMOIRE
	};


	typedef enum choixMenu ChoixMenu;
	enum choixMenu {
		CHOIX_MIN,
		CHARGER_JOUEURS_PERSONNAGES = 1,
		AJOUTER_JOUEUR_PERSONNAGES,
		AJOUTER_PERSONNAGE_PERSONNAGES,
		SUPPRIMER_JOUEUR,
		AFFICHER_JOUEURS_PERSONNAGES,
		SAUVER_JOUEURS_PERSONNAGES,
		QUITTER
	};
#endif
