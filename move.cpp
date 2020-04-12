#include <QtGlobal>
#include <QtDebug>
#include "move.h"

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
