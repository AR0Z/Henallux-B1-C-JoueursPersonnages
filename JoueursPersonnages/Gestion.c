#include "JoueursPerso.h"


bool joueurExiste(Joueur* pDebutJoueur, char pseudo[TPSEUDO], Joueur** pJoueur, Joueur** pSauvJoueur) {
	*pJoueur = pDebutJoueur;
	*pSauvJoueur = NULL;

	while (*pJoueur != NULL && strcmp(pseudo, (*pJoueur)->pseudo) > 0) {
		(*pSauvJoueur) = (*pJoueur);
		*pJoueur = (*pJoueur)->pSuiv;
	}
	return (*pJoueur) != NULL && strcmp(pseudo, (*pJoueur)->pseudo) == 0;
}

bool nouveauJoueur(Joueur** pNouvJoueur) {
	*pNouvJoueur = (Joueur*)malloc(sizeof(Joueur));

	return *pNouvJoueur != NULL;
}

void ajouteJoueur(Joueur** pDebutJoueur, char pseudo[TPSEUDO], Joueur** pNouvJoueur, Joueur* pJoueur, Joueur* pSauvJoueur) {
	strcpy_s((*pNouvJoueur)->pseudo, TPSEUDO, pseudo);
	(*pNouvJoueur)->pDebPersonnages = NULL;

	if (pJoueur == (*pDebutJoueur)) {
		*pDebutJoueur = *pNouvJoueur;
	} else {
		pSauvJoueur->pSuiv = (*pNouvJoueur);
	}
	(*pNouvJoueur)->pSuiv = pJoueur;
}

void supprimeJoueur(Joueur** pDebJoueurs, Joueur* pJoueur, Joueur* pSauvJoueur) {
	Personnage* pDebPersonnages = pJoueur->pDebPersonnages;

	libereJoueurPersonnages(&pDebPersonnages);

	if (pJoueur == (*pDebJoueurs)) {
		*pDebJoueurs = pJoueur->pSuiv;
	} else {
		pSauvJoueur->pSuiv = pJoueur->pSuiv;
	}

	libereJoueur(&pJoueur);
}

void libereJoueur(Joueur** pJoueur) {
	free(*pJoueur);
	*pJoueur = NULL;
}

bool personnageExiste(Joueur* pDebutJoueur, char nom[TNOM]) {
	Joueur* pJoueur = pDebutJoueur;
	Personnage* pPerso;
	bool existe = false;
	while (pJoueur != NULL && !existe) {
		pPerso = pJoueur->pDebPersonnages;
		while (pPerso != NULL && strcmp(pPerso->nom, nom) > 0) {
			pPerso = pPerso->pSuiv;
		}
		existe = pPerso != NULL && strcmp(pPerso->nom, nom) == 0;
		pJoueur = pJoueur->pSuiv;
	}
	return existe;
}

int nbPersonnages(Joueur* pJoueur) {
	Personnage* pPerso = pJoueur->pDebPersonnages;
	int nbrPersonnages = 0;
	while (pPerso != NULL) {
		pPerso = pPerso->pSuiv;
		nbrPersonnages++;
	}

	return nbrPersonnages;
}

bool nouveauPersonnage(Personnage** pNouvPerso) {
	*pNouvPerso = (Personnage*)malloc(sizeof(Personnage));

	return *pNouvPerso != NULL;
}

void ajoutePersonnage(Joueur* pJoueur, char nom[TNOM], int points, Personnage* pNouvPerso) {
	strcpy_s(pNouvPerso->nom, TNOM, nom);
	pNouvPerso->pointsExprerience = points;

	pNouvPerso->pSuiv = pJoueur->pDebPersonnages;
	pJoueur->pDebPersonnages = pNouvPerso;
}

void listeJoueurs(Joueur* pDebJoueurs) {
	Joueur* pJoueur = pDebJoueurs;
	while (pJoueur != NULL) {
		printf("%s", pJoueur->pseudo);
		ENTER;
		Personnage* pPerso = pJoueur->pDebPersonnages;
		while (pPerso != NULL) {
			TAB;
			printf("%s -- %d XP", pPerso->nom, pPerso->pointsExprerience);
			ENTER;
			pPerso = pPerso->pSuiv;
		}
		pJoueur = pJoueur->pSuiv;
	}
}

void liberePersonnage(Personnage** pPerso) {
	free(*pPerso);
	*pPerso = NULL;
}

void libereJoueurPersonnages(Personnage** pDebPerso) {
	Personnage* pPerso = *pDebPerso;
	while (pPerso != NULL) {
		Personnage* pSauvPerso = pPerso->pSuiv;

		liberePersonnage(&pPerso);

		pPerso = pSauvPerso;
	}

	free(*pDebPerso);
	*pDebPerso = NULL;
}

void libereJoueursPersonnages(Joueur** pDebJoueurs) {
	Joueur* pJoueur = *pDebJoueurs;
	libereJoueur(&pJoueur);
	while (pJoueur != NULL) {
		Joueur* pJoueurSave = pJoueur->pSuiv;
	
		Personnage* pDebPersonnages = pJoueur->pDebPersonnages;
	
		libereJoueurPersonnages(&pDebPersonnages);
	
		pJoueur = pJoueurSave;
	}
}

