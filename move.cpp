#include <QtGlobal>
#include <QtDebug>
#include "move.h"


int Move::Fusion_Possible_par_Ligne(Case *grid){
    //fonction pour compter le nombre de fusions possibles pour un mouvement en ligne nb : quelque soit le sens, droit ou gauche, le nombre de fusions
    //pour un mouvemnt en colonne est le même
    int l, c;
    int res = 0;
    for (l=0;l<COTE;l++){
        int temp = grid[l].valeur;
        for(c=1;c<COTE;c++) {
            int x=c*COTE+l;
            if (grid[x].valeur == temp) {
                res=res+1;
                temp = 0;
            }
            else
            {
                temp = grid[x].valeur
            }

        }
    }

    return res;

}


int Move::Fusion_Possible_par_Colonne(Case *grid){
    //fonction pour compter le nombre de fusions possibles pour un mouvement en colonne nb : quelque soit le sens, haut ou bas, le nombre de fusions
    //pour un mouvemnt en colonne est le même
    int l, c;
    int res = 0;
    for (c=0;c<COTE;c++){
        int temp = grid[COTE*c].valeur;
        for(l=1;l<COTE;l++) {
            int x=c*COTE+l;
            if (grid[x].valeur == temp) {
                res=res+1;
                temp = 0;
            }
            else
            {
                temp = grid[x].valeur
            }

        }
    }

    return res;

}


bool Move::move(Case *grid, int &val, bool anim){

    int nbMove = 0;
    bool moved;

    do {
        moved = false;

        do {

        }
    }

    if(grid[voisin].valeur == grid)


}

