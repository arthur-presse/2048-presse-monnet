#ifndef MOVE_H
#define MOVE_H

#include "common.h"


// création d'une classe abstraite de mouvement
class Move
{
protected:
    int x;
    virtual bool next(void) = 0;
    virtual int getcloser(int x) = 0;
    virtual void init(void) = 0;
    int COTE;
    int NbCase;
public:
    bool doMove(Case *grid, int &val);
    explicit Move(int cote);
};
//---Création de chacun des déplacements---

//mouvement vers le haut
class MoveUp : public Move {
protected:
    virtual int getcloser(int x);
    virtual bool next(void);
    virtual void init(void);
public:
    explicit MoveUp(int cote);
};

//mouvement vers le bas
class MoveDown : public Move {
protected:
    virtual int getcloser(int x);
    virtual bool next(void);
    virtual void init(void);
public:
    explicit MoveDown(int cote);
};

//mouvement vers la gauche
class MoveLeft : public Move {
protected:
    virtual int getcloser(int x);
    virtual bool next(void);
    virtual void init(void);
public:
    explicit MoveLeft(int cote);
};

//mouvement vers la droite
class MoveRight : public Move {
protected:
    virtual int getcloser(int x);
    virtual bool next(void);
    virtual void init(void);
public:
    explicit MoveRight(int cote);
};
#endif // MOVE_H
