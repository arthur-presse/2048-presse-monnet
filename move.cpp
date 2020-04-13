#include <QtGlobal>
#include <QtDebug>
#include "move.h"
Move::Move(int cote){
    COTE = cote;
    NbCase = cote * cote;
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

// - - - - - - - - - - - - MoveUp - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
MoveUp::MoveUp(int cote) : Move(cote){}

bool MoveUp::next(void){
    if(x + 1 < NbCase) {
        x=x+1;
        return true;
    }

    return false;
}

int MoveUp::getcloser(int x){
    return x - COTE;
}

void MoveUp::init(void){
    x = COTE;
}

// - - - - - - - - - - - - MoveDown - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
MoveDown::MoveDown(int cote) : Move(cote){}
bool MoveDown::next(void){
    if(x - 1 >= 0) {
        x=x-1;

        return true;
    }

    return false;
}


int MoveDown::getcloser(int x){
    return x + COTE;
}

void MoveDown::init(void){
    x = NbCase - COTE - 1;
}

// - - - - - - - - - - - - MoveLeft - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
MoveLeft::MoveLeft(int cote) : Move(cote){}
bool MoveLeft::next(void){
    if(x + 1 < NbCase) {
        x=x+1;
        if(x % COTE == 0) {
            x=x+1;
        }

        return true;
    }

    return false;
}


int MoveLeft::getcloser(int x){
    return x - 1;
}

void MoveLeft::init(void){
    x = 1;
}

// - - - - - - - - - - - - MoveRight - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
MoveRight::MoveRight(int cote) : Move(cote){}
bool MoveRight::next(void){
    if(x - 1 >= 0) {
        x=x-1;
        if(x % COTE == COTE - 1) {
            x=x-1;
        }

        return true;
    }

    return false;
}


int MoveRight::getcloser(int x){
    return x + 1;
}

void MoveRight::init(void){
    x = NbCase-2;
}
