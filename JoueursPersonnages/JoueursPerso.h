#ifndef JOUEURSPERSO_H
#define JOUEURSPERSO_H

	#include "Constantes.h"
	#include "Lexique.h"

	#define FIJOEURS "Joueurs.data"

	typedef  struct personnage Personnage;
	struct personnage {
		char nom[TNOM];
		int pointsExprerience;
		Personnage* pSuiv;
	};

	typedef struct personnageEnregistrement PersonnageEnregistrement;
	struct personnageEnregistrement {
		char nom[TNOM];
		int pointsExprerience;
	};

	typedef  struct joueur Joueur;
	struct joueur {
		char pseudo[TPSEUDO];
		Personnage* pDebPersonnages;
		Joueur* pSuiv;
	};

	typedef  struct joueurEnregistrement JoueurEnregistrement;
	struct joueurEnregistrement {
		char pseudo[TPSEUDO];
		int nbPerso;
	};

	void dialogues(Message* pLexique);
	CodeErreur choixObtenu(Message* pLexique, ChoixMenu MENU_PRINCIPAL);
	CodeErreur ajouterJoueurPersonnages(Message* pLexique, Joueur** pDebJoueurs);
	CodeErreur ajouterPersonnageAJoueur(Message* pLexique, Joueur** pDebJoueurs, Joueur* pJoueur, Personnage* pNouvPerso);
	void pseudoObtenu(Message* pLexique, char pseudo[TPSEUDO]);
	void nomObtenu(Message* pLexique, char nom[TNOM]);
	int pointsObtenus(Message* pLexique);
	int reponseObtenue(Message* pLexique, int numMessage);
	void afficherJoueursPersonnages(Message* pLexique, Joueur* pDebJoueurs);
	CodeErreur sauverJoueursPersonnages(Message* pLexique, Joueur* pDebJoueurs);
	CodeErreur chargerJoueursPersonnages(Message* pLexique, Joueur** pDebJoueurs);
	CodeErreur ajouterPersonnage(Message* pLexique, Joueur* pDebJoueurs);
	CodeErreur supprimerJoueurPersonnages(Message* pLexique, Joueur** pDebJoueurs);

	bool nouveauJoueur(Joueur** pNouvJoueur);
	bool joueurExiste(Joueur* pDebutJoueur, char pseudo[TPSEUDO], Joueur** pJoueur, Joueur** pSauvJoueur);
	void libereJoueur(Joueur** pJoueur);
	void ajouteJoueur(Joueur** pDebutJoueur, char pseudo[TPSEUDO], Joueur** pNouvJoueur, Joueur* pJoueur, Joueur* pSauvJoueur);
	bool nouveauPersonnage(Personnage** pNouvPerso);
	void liberePersonnage(Personnage** pPerso);
	void ajoutePersonnage(Joueur* pJoueur, char nom[TNOM], int points, Personnage* pNouvPerso);
	int nbPersonnages(Joueur* pJoueur);
	bool personnageExiste(Joueur* pDebutJoueur, char nom[TNOM]);
	void listeJoueurs(Joueur* pDebJoueurs);
	void supprimeJoueur(Joueur** pDebJoueurs, Joueur* pJoueur, Joueur* pSauvJoueur);


	CodeErreur fichierExiste();
	CodeErreur sauverJoueurs(Joueur* pDebJoueurs);
	CodeErreur chargerJoueurs(Joueur** pDebJoueurs);
	void libereJoueursPersonnages(Joueur** pDebJoueurs);
	void libereJoueurPersonnages(Personnage** pDebPerso);
#endif