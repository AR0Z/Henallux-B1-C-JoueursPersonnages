#include "JoueursPerso.h"

CodeErreur fichierExiste() {
	CodeErreur codeErreur = PAS_D_ERREUR;

	FILE* pFiJoueurs;

	fopen_s(&pFiJoueurs, FIJOEURS, "rb");

	if (pFiJoueurs == NULL) {
		return FICHIER_INEXISTANT;
	}
	fclose(pFiJoueurs);

	return codeErreur;
}

CodeErreur sauverJoueurs(Joueur* pDebJoueurs) {
	CodeErreur codeErreur = PAS_D_ERREUR;

	FILE* pFiJoueurs;

	fopen_s(&pFiJoueurs, FIJOEURS, "wb");

	if (pFiJoueurs == NULL) {
		return FICHIER_INEXISTANT;
	}
	Joueur* pJoueur = pDebJoueurs;
	while (pJoueur != NULL) {
		JoueurEnregistrement joueur;
		strcpy_s(joueur.pseudo, TPSEUDO, pJoueur->pseudo);
		joueur.nbPerso = nbPersonnages(pJoueur);

		fwrite(&joueur, sizeof(JoueurEnregistrement), 1, pFiJoueurs);

		Personnage* pPerso = pJoueur->pDebPersonnages;
		while (pPerso != NULL) {
			PersonnageEnregistrement perso;
			strcpy_s(perso.nom, TNOM, pPerso->nom);
			perso.pointsExprerience = pPerso->pointsExprerience;

			fwrite(&perso, sizeof(PersonnageEnregistrement), 1, pFiJoueurs);

			pPerso = pPerso->pSuiv;
		}
		pJoueur = pJoueur->pSuiv;
	}
	fclose(pFiJoueurs);
	return codeErreur;
}

CodeErreur chargerJoueurs(Joueur** pDebJoueurs) {
	CodeErreur codeErreur = PAS_D_ERREUR;

	FILE* pFiJoueurs;

	fopen_s(&pFiJoueurs, FIJOEURS, "rb");

	if (pFiJoueurs == NULL) {
		return FICHIER_INEXISTANT;
	}

	bool allocationOk = true;

	Joueur* pJoueur = NULL;
	Joueur* pSauvJoueur = NULL;
	*pDebJoueurs = NULL;

	JoueurEnregistrement joueur;
	fread_s(&joueur, sizeof(JoueurEnregistrement), sizeof(JoueurEnregistrement), 1, pFiJoueurs);

	while (!feof(pFiJoueurs) && allocationOk) {
		Joueur* pNouvJoueur;
		allocationOk = nouveauJoueur(&pNouvJoueur);
		if (!allocationOk) {
			return ALLOCATION_MEMOIRE;
		}
		ajouteJoueur(pDebJoueurs, joueur.pseudo, &pNouvJoueur, pJoueur, pSauvJoueur);
		pSauvJoueur = pNouvJoueur;

		int iPersonnage = 0;

		while (iPersonnage < joueur.nbPerso && allocationOk) {
			Personnage* pNouvPerso;

			allocationOk = nouveauPersonnage(&pNouvPerso);

			if (!allocationOk) {
				return ALLOCATION_MEMOIRE;
			}

			PersonnageEnregistrement perso;
			fread_s(&perso, sizeof(PersonnageEnregistrement), sizeof(PersonnageEnregistrement), 1, pFiJoueurs);

			ajoutePersonnage(pNouvJoueur, perso.nom, perso.pointsExprerience, pNouvPerso);

			iPersonnage++;
		}
		fread_s(&joueur, sizeof(JoueurEnregistrement), sizeof(JoueurEnregistrement), 1, pFiJoueurs);
	}

	fclose(pFiJoueurs);
	return codeErreur;
}

