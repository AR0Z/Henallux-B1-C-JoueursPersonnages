#ifndef LEXIQUE_H
#define LEXIQUE_H
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <stdbool.h> 

	#include "Constantes.h"

	#define FIFRANCAIS "Francais.txt"
	#define FIENGLISH "English.txt"

	#define TNOMFICHIER 20
	#define TTITRE		100
	#define TMENU		100
	#define TTXT		150

	typedef enum numMessage NumMessage;
	enum numMessage {
		// Menu
		MENU_PRINCIPAL = 1001,
		// Messages d'obtention
		OBT_PSEUDO = 2001,
		OBT_NOM,
		OBT_POINTS,
		OBT_ENCORE = 2101,
		OBT_CHOIX,
		OBT_CONTINUER,
		// Titres
		TITRE_PRINCIPAL = 3000,
		TITRE_JOUEUR = 3001,
		TITRE_PERSONNAGE = 3002,
		TITRE_AFFICHAGE = 3003,
		TITRE_JOUEUR_AJOUT = 3101,
		TITRE_JOUEUR_ANNUL = 3102,
		TITRE_PERSO_AJOUT = 3201,
		TITRE_PERSO_ANNUL = 3202,
		TITRE_LISTE_JOUEURS = 3301,
		CHARGEMENT = 3401,
		SAUVEGARDE,
		AUCUN_JOUEUR,
		AUCUN_PERSONNAGE,
		MODIFICATIONS_ANNULEES,
		// Numéro de début des messages d'erreur
		NUM_DEB_MESSAGE_ERREUR = 5000,

	};

	typedef struct message Message;

	// Fonctions publiques

	CodeErreur chargerLexique(Message** pPLexique);
	// Chargement du fichier des différents textes à afficher dans une liste chainée simple
	// Pré : pPLexique est l'adresse de l'adresse début de la liste (pLexique)
	// Post : renvoie un code erreur sur l'erreur éventuellement rencontrée 
	//        si pas d'erreur, pLexique contient l'adresse début de la liste des messages textes
	
	void afficherMessage(Message* pLexique, int numMessage);
	// Affiche un message texte
	// Pré : pLexique est l'adresse début de la LC des messages
	//       numMessage est le numéro du message à afficher (0 < numéro <= numMax dans le fichier)
	// Post : le message sera affiché
	
	int afficherMenu(Message* pLexique, int debMenu);
	// Affiche un menu 
	// Pré : pLexique est l'adresse début de la LC des messages
	//       debMenu est le numéro du titre du menu à afficher (0 < numéro <= numMax dans le fichier)
	// Post : le titre du menu et ses options seront affichés

	void afficherTitre(Message* pLexique, int numTitre);
	// Affiche un titre après avoir effacé l'écran
	// Pré : pLexique est l'adresse début de la LC des messages
	//       numTitre est le numéro du titre à afficher (0 < numéro <= numMax dans le fichier)
	// Post : le titre sera affiché en début de page

	void libererLexique(Message* pLexique);
	// Libère la LC des messages
	// pLexique est l'adresse début de la liste
#endif
