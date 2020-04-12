#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QTimer>
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
    QString grid2string(void);
protected:
    virtual void paintEvent(QPaintEvent *);
private:
    Grid grid;
    int score;
    bool win;
    QTimer *timer;
    int iter = 0;
    bool add_item(void);
    bool check_lost(void);   
    eventResult action(Move *move);
private slots:
    void timer_timeout(void);
};

#endif // GAMEWIDGET_H
