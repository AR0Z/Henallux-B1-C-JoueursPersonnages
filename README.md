# JoueursPersonnages
Summary exercise of the different modules seen in class :

- Module 0 - Two index tables
- Module 1 - Structures
- Module 2 - Files
- Module 3 - Pointers
- Module 4 - Complements

---

## Content of the code 

### Resource files :

- Francais.txt => file containing all the texts of the program
- Lexique.obj => containing all the functions to use the lexicon

### Header files :

- Constantes.h => containing constants, error codes and menu choices
- JoueursPerso.h => containing the structs and signatures of the project functions
- Lexique.h => containing the message enumeration and function signatures of `Lexique.obj`

### Source Files :

- Principale.c => This module contains the main function and the lexicon loading

- Interface.c => This module contains all the functions related to the dialogue with the user, such as the display of the various menus, the obtaining of information (names of the characters...) and the display "in clear" of the error messages returned by the more mechanical functions (of Management and File for example).

- Gestion.c => This module contains all the functions related to the linked lists held in memory and storing the players and their characters.

- Fichier.c => This module contains all functions related to the use of the player and character data file, including saving and loading data.
