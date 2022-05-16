#include "JoueursPerso.h"

void main(void) {
	Message* pLexique = NULL;

	CodeErreur codeErreur = chargerLexique(&pLexique);

	if (codeErreur != PAS_D_ERREUR) {
		if (codeErreur == ALLOCATION_MEMOIRE) {
			printf("Erreur memoire/Memory error");

			libererLexique(pLexique);
		} else if (codeErreur == FICHIER_INEXISTANT) {
			printf("Erreur ouverture fichier/File opening error");
		}
	} else {
		dialogues(pLexique);
		libererLexique(pLexique);
	}
}