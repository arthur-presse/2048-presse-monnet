#ifndef COMMON_H
#define COMMON_H

#define COTE    4
#define NbCase  (COTE^2)

typedef struct {
    //value est la valeur de la case de la grille
    int value;
    // new et fusion servent à l'affichage graphique du jeu
    bool newvalue;
    bool fusion;
}Case;
//définition de la grille que nous allons utiliser pour stocker toutes les valeurs durant une partie
typedef Case Grid[NbCase];

#endif // COMMON_H
