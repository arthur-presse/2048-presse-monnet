#ifndef MOVE_H
#define MOVE_H

#include "common.h"



class Move
{
protected:
    typedef int (Move::* )(Case *grid)

    int x;

    virtual int getclose(int x) = 0;
    virtual bool next(void) = 0;
    virtual void init(void) = 0;
    virtual Move::deep getfusion(void) = 0;
    int Fusion_Possible_par_Ligne(Case *grid);
    int Fusion_Possible_par_Colonne(Case *grid);



public:
    bool move(Case *grille, int &val, bool anim = true);

};

#endif // MOVE_H
