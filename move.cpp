#include <QtGlobal>
#include <QtDebug>
#include "move.h"


int Move::Fusion_Possible_par_Ligne(SCase *grille){
    int l, c;
    int res = 0;
    for (l=0;l<COTE;l++){
        int temp = grille[l].valeur;
        for(c=1;c<COTE;c++) {
            int x=c*COTE+l;
            if (grille[x].valeur == temp) {
                res=res+1;
                temp = 0;
            }
            else
            {
                temp = grille[x].valeur
            }

        }
    }

    return res;

}
