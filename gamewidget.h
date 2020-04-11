#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include "common.h"
#include "move.h"

class GameWidget : public QWidget
{
    Q_OBJECT
public:
    typedef enum {isWon, isMoving, isLost, isNone} eventResult;
    explicit GameWidget(QWidget *parent = nullptr);
    int getScore(void);
    void newGame(void);
    eventResult Up(void);
    eventResult Down(void);
    eventResult Left(void);
    eventResult Right(void);
private:
    Grid grid;
    int score;
    bool win;
    bool add_item(void);
    bool check_lost(void);
    eventResult action(Move *move);
};

#endif // GAMEWIDGET_H
