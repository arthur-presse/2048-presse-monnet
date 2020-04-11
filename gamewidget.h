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
    void newGame(void);
    bool add_item(void);
    eventResult action(Move *move);
    bool check_lost(void);
private:
    Grid grid;
    int score;
    bool win;



};

#endif // GAMEWIDGET_H
