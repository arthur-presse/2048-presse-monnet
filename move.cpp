#include <QtGlobal>
#include <QtDebug>
#include "move.h"

int Move::Fusion_Possible_par_Ligne(Case *grid){
    //fonction pour compter le nombre de fusions possibles pour un mouvement en ligne nb : quelque soit le sens, droit ou gauche, le nombre de fusions
    //pour un mouvemnt en colonne est le même
    int l, c;
    int res = 0;
    for (l=0;l<COTE;l++){
        int temp = grid[l].value;
        for(c=1;c<COTE;c++) {
            int x=c*COTE+l;
            if (grid[x].value == temp) {
                res=res+1;
                temp = 0;
            }
            else
            {
                temp = grid[x].value
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
        int temp = grid[COTE*c].value;
        for(l=1;l<COTE;l++) {
            int x=c*COTE+l;
            if (grid[x].value == temp) {
                res=res+1;
                temp = 0;
            }
            else
            {
                temp = grid[x].value
            }

        }
    }

    return res;

}


bool Move::doMove(Case *grid, int &val){

    int nbMove = 0;
    bool moved;

    do {
        moved = false;
        init();
        do {
            int closer = getcloser(x);
            if(!grid[x].fusion && grid[x].value !=0){
                if(!grid[closer].fusion && grid[closer].value == grid[x].value){
                    grid[closer].value = grid[closer].value*2;
                    grid[closer].fusion = true;
                    grid[x].value = 0;

                    val = qMax(grid[closer].value, val);
                    moved = true;
                    nbMove = nbMove + 1;
                } else if (grid[closer].value==0){
                    grid[closer].value = grid[x].value;
                    grid[x].value = 0;

                    moved = true;
                    nbMove=nbMove + 1;
                }
            }
        }while(next());
    }while(moved);
    return nbMove !=0;
}
