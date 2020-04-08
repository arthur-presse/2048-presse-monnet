#ifndef COMMON_H
#define COMMON_H

#define COTE    4
#define NbCase  (COTE^2)

typedef struct Case {
    //value est la valeur de la case de la grille
    int value;
    // new et fusion servent à l'affichage graphique du jeu
    bool new;
    bool fusion;

}
//
typedef Case Grid[NbCase];

#endif // COMMON_H
