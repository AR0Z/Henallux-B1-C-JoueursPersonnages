#include "JoueursPerso.h"

void dialogues(Message* pLexique) {
	CodeErreur codeErreur = PAS_D_ERREUR;
	Joueur* pDebJoueurs = NULL;

	int choix = choixObtenu(pLexique, MENU_PRINCIPAL);
	while (choix != QUITTER) {
		switch (choix) {
		case CHARGER_JOUEURS_PERSONNAGES:
			codeErreur = chargerJoueursPersonnages(pLexique, &pDebJoueurs);
			PAUSE;
			break;
		case AJOUTER_JOUEUR_PERSONNAGES:
			codeErreur = ajouterJoueurPersonnages(pLexique, &pDebJoueurs);
			break;
		case AJOUTER_PERSONNAGE_PERSONNAGES:
			ajouterPersonnage(pLexique, pDebJoueurs);
			break;
		case SUPPRIMER_JOUEUR:
			supprimerJoueurPersonnages(pLexique, &pDebJoueurs);
			break;
		case AFFICHER_JOUEURS_PERSONNAGES:
			afficherJoueursPersonnages(pLexique, pDebJoueurs);
			PAUSE;
			break;
		case SAUVER_JOUEURS_PERSONNAGES:
			sauverJoueursPersonnages(pLexique, pDebJoueurs);
			PAUSE;
			break;
		}

		if (codeErreur != PAS_D_ERREUR) {
			afficherMessage(pLexique, NUM_DEB_MESSAGE_ERREUR + codeErreur);
			codeErreur = PAS_D_ERREUR;
			PAUSE;
		}

		choix = choixObtenu(pLexique, MENU_PRINCIPAL);

	}
}

CodeErreur ajouterJoueurPersonnages(Message* pLexique, Joueur** pDebJoueurs) {
	Joueur* pNouvJoueur;
	CodeErreur codeErreur;
	bool allocationOk = nouveauJoueur(&pNouvJoueur);

	if (!allocationOk) {
		return ALLOCATION_MEMOIRE;
	}
	codeErreur = PAS_D_ERREUR;
	afficherTitre(pLexique, TITRE_PERSO_AJOUT);
	char pseudo[TPSEUDO];
	pseudoObtenu(pLexique, pseudo);
	Joueur* pJoueur;
	Joueur* pSauvJoueur;
	bool joueurPresent = joueurExiste(*pDebJoueurs, pseudo, &pJoueur, &pSauvJoueur);
	if (joueurPresent) {
		return JOUEUR_DEJA_PRESENT;
		libereJoueur(&pNouvJoueur);
	}
	ajouteJoueur(pDebJoueurs, pseudo, &pNouvJoueur, pJoueur, pSauvJoueur);
	int reponse;
	do {
		Personnage* pNouvPerso;
		allocationOk = nouveauPersonnage(&pNouvPerso);
		if (!allocationOk) {
			return ALLOCATION_MEMOIRE;
		}

		codeErreur = ajouterPersonnageAJoueur(pLexique, pDebJoueurs, pNouvJoueur, pNouvPerso);

		if (codeErreur == PAS_D_ERREUR) {
			reponse = reponseObtenue(pLexique, OBT_ENCORE);
		}
	} while (allocationOk && codeErreur == PAS_D_ERREUR && reponse == OUI);
	return codeErreur;
}

CodeErreur ajouterPersonnageAJoueur(Message* pLexique, Joueur** pDebJoueurs, Joueur* pJoueur, Personnage* pNouvPerso) {
	CodeErreur codeErreur = PAS_D_ERREUR;

	char nom[TNOM];
	nomObtenu(pLexique, nom);
	bool persoExiste = personnageExiste(*pDebJoueurs, nom);
	if (persoExiste) {
		codeErreur = PERSONNAGE_DEJA_PRESENT;
		liberePersonnage(&pNouvPerso);
	} else {
		int nbrPerso = nbPersonnages(pJoueur);
		if (nbrPerso < NBMAXPERSO) {
			int points = pointsObtenus(pLexique);

			ajoutePersonnage(pJoueur, nom, points, pNouvPerso);
		} else {
			codeErreur = NB_MAX_PERSO_ATTEINT;
		}

	}
	return codeErreur;
}

CodeErreur ajouterPersonnage(Message* pLexique, Joueur* pDebJoueurs) {
	CodeErreur codeErreur = PAS_D_ERREUR;
	Personnage* pNouvPerso;
	bool allocationOk = nouveauPersonnage(&pNouvPerso);
	if (!allocationOk) {
		codeErreur = ALLOCATION_MEMOIRE;
	} else {
		afficherTitre(pLexique, TITRE_PERSO_AJOUT);
		char pseudo[TPSEUDO];
		pseudoObtenu(pLexique, pseudo);
		Joueur* pJoueur;
		Joueur* pSauvJoueur;
		bool joueurPresent = joueurExiste(pDebJoueurs, pseudo, &pJoueur, &pSauvJoueur);

		if (!joueurPresent) {
			codeErreur = JOUEUR_ABSENT;
			liberePersonnage(&pNouvPerso);
		} else {
			ajouterPersonnageAJoueur(pLexique, &pDebJoueurs, pJoueur, pNouvPerso);
		}
	}

	return codeErreur;
}


int choixObtenu(Message* pLexique, ChoixMenu MENU_PRINCIPAL) {
	int choix;
	bool choixValide;
	do {
		int maxChoix = afficherMenu(pLexique, MENU_PRINCIPAL);
		afficherMessage(pLexique, OBT_CHOIX);

		scanf_s("%d", &choix);

		choixValide = choix >= 1 && choix <= maxChoix;

		if (!choixValide)
			afficherMessage(pLexique, NUM_DEB_MESSAGE_ERREUR + MAUVAIS_CHOIX);
	} while (!choixValide);

	return choix;
}

void pseudoObtenu(Message* pLexique, char pseudo[TPSEUDO]) {
	bool pseudoValide;
	do {
		afficherMessage(pLexique, OBT_PSEUDO);
		scanf_s("%s", pseudo, TPSEUDO);

		pseudoValide = ((pseudo[0] != ' ') && (pseudo[0] >= 'A' && pseudo[0] <= 'Z')); // ctype --> isupper
		if (!pseudoValide) {
			afficherMessage(pLexique, NUM_DEB_MESSAGE_ERREUR + PSEUDO_NON_VALIDE);
		}
	} while (!pseudoValide);
}

void nomObtenu(Message* pLexique, char nom[TNOM]) {
	bool nomValide;
	do {
		afficherMessage(pLexique, OBT_NOM);
		scanf_s("%s", nom, TNOM);

		nomValide = (nom[0] != ' ') && (nom[0] >= 'A' && nom[0] <= 'Z');
		if (!nomValide) {
			afficherMessage(pLexique, NUM_DEB_MESSAGE_ERREUR + NOM_NON_VALIDE);
		}
	} while (!nomValide);
}

int pointsObtenus(Message* pLexique) {
	bool pointsValide;
	int points;
	do {
		afficherMessage(pLexique, OBT_POINTS);
		scanf_s("%d", &points);

		pointsValide = points >= 1;
		if (!pointsValide) {
			afficherMessage(pLexique, NUM_DEB_MESSAGE_ERREUR + POINTS_NON_VALIDES);
		}
	} while (!pointsValide);

	return points;
}

int reponseObtenue(Message* pLexique, int numMessage) {
	bool reponseValide;
	int reponse;
	do {
		afficherMessage(pLexique, numMessage);
		scanf_s("%d", &reponse);

		reponseValide = reponse == OUI || reponse == NON;
		if (!reponseValide) {
			afficherMessage(pLexique, NUM_DEB_MESSAGE_ERREUR + REPONSE_NON_VALIDE);
		}
	} while (!reponseValide);

	return reponse;
}

void afficherJoueursPersonnages(Message* pLexique, Joueur* pDebJoueurs) {
	if (pDebJoueurs == NULL) {
		afficherMessage(pLexique, AUCUN_JOUEUR);
	} else {
		afficherTitre(pLexique, TITRE_LISTE_JOUEURS);
		listeJoueurs(pDebJoueurs);
	}
}

CodeErreur sauverJoueursPersonnages(Message* pLexique, Joueur* pDebJoueurs) {
	CodeErreur codeErreur = PAS_D_ERREUR;

	if (pDebJoueurs == NULL) {
		afficherMessage(pLexique, AUCUN_JOUEUR);
	} else {
		afficherTitre(pLexique, SAUVEGARDE);

		codeErreur = sauverJoueurs(pDebJoueurs);
	}

	return codeErreur;
}

CodeErreur supprimerJoueurPersonnages(Message* pLexique, Joueur** pDebJoueurs) {
	CodeErreur codeErreur = PAS_D_ERREUR;

	afficherTitre(pLexique, TITRE_JOUEUR_ANNUL);
	char pseudo[TPSEUDO];
	pseudoObtenu(pLexique, pseudo);

	Joueur* pJoueur;
	Joueur* pSauvJoueur;
	bool joueurPresent = joueurExiste(*pDebJoueurs, pseudo, &pJoueur, &pSauvJoueur);

	if (!joueurPresent) {
		codeErreur = JOUEUR_ABSENT;
	} else {
		supprimeJoueur(pDebJoueurs, pJoueur, pSauvJoueur);
	}

	return codeErreur;
}

CodeErreur chargerJoueursPersonnages(Message* pLexique, Joueur** pDebJoueurs) {
	CodeErreur codeErreur = PAS_D_ERREUR;
	codeErreur = fichierExiste();

	if (codeErreur == PAS_D_ERREUR) {
		afficherTitre(pLexique, CHARGEMENT);

		if (*pDebJoueurs != NULL) {
			afficherMessage(pLexique, MODIFICATIONS_ANNULEES);
			int reponse = reponseObtenue(pLexique, OBT_CONTINUER);

			if (reponse == OUI) {
				libereJoueursPersonnages(pDebJoueurs);
				codeErreur = chargerJoueurs(pDebJoueurs);
			}
		} else {
			codeErreur = chargerJoueurs(pDebJoueurs);
		}
	}

	return codeErreur;
}