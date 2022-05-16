# JoueursPersonnages
Exercice récapitulatif des différents module vu en cours :

- Module 0 - Les tableaux à deux indices
- Module 1 - Les structures
- Module 2 - Les fichiers
- Module 3 - Les pointeurs
- Module 4 - Compléments

---

## Contenu du code 

### Fichiers ressources :

- Francais.txt => fichier contenant tous les textes du programme
- Lexique.obj => contenant toutes les fonctions pour utiliser le lexique

### Fichiers d'en-tête :

- Constantes.h => contenant les constantes, les enumérations des codes erreurs et des choix du menu
- JoueursPerso.h => contenant les structs et les signatures des fonctions du projet
- Lexique.h => contenant l'enumération des message et les signatures des fonctions de `Lexique.obj`

### Fichiers Sources :

- Principale.c => Ce module contient la fonction main et le chargement du lexique

- Interface.c => Ce module contient toutes les fonctions relatives au dialogue avec l’utilisateur, comme par
exemple l’affichage des divers menus, les obtentions d’informations (noms des
personnages...) et l’affichage « en clair » des messages d’erreur renvoyés par les fonctions
plus mécaniques (de Gestion et de Fichier par exemple).

- Gestion.c => Ce module contient toutes les fonctions liées aux listes chaînées retenues en mémoire
et stockant les joueurs et leurs personnages.

- Fichier.c => Ce module contient toutes les fonctions liées à l’utilisation du fichier de données des
joueurs et de leurs personnages ; entre autres, la sauvegarde et le chargement des
données.
