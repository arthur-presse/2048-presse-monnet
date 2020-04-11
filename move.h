#ifndef MOVE_H
#define MOVE_H

#include "common.h"



class Move
{
protected:
    typedef int (Move::* deep)(Case *grid);

    int x;
    virtual bool next(void) = 0;
    virtual int getcloser(int x) = 0;
    virtual void init(void) = 0;

    virtual Move::deep getfusion(void) = 0;
    int Fusion_Possible_par_Ligne(Case *grid);
    int Fusion_Possible_par_Colonne(Case *grid);

public:
    bool doMove(Case *grid, int &val);
};
//---Création de chacun des déplacements---

//mouvement vers le haut
class MoveHigh : public Move {
protected:
    virtual int getcloser(int x);
    virtual bool next(void);
    virtual void init(void);
    virtual Move::deep getfusion(void);
};

//mouvement vers le bas
class MoveDown : public Move {
protected:
    virtual int getcloser(int x);
    virtual bool next(void);
    virtual void init(void);
    virtual Move::deep getfusion(void);
};

//mouvement vers la gauche
class MoveLeft : public Move {
protected:
    virtual int getcloser(int x);
    virtual bool next(void);
    virtual void init(void);
    virtual Move::deep getfusion(void);
};

//mouvement vers la droite
class MoveRight : public Move {
protected:
    virtual int getcloser(int x);
    virtual bool next(void);
    virtual void init(void);
    virtual Move::deep getfusion(void);
};
#endif // MOVE_H
