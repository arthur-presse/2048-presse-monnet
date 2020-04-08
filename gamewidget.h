#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include "common.h"

class GameWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GameWidget(QWidget *parent = nullptr);
    void newGame(void);
    bool add_item(void);
private:
    Grid grid;
    int score;
    bool win;


};

#endif // GAMEWIDGET_H
