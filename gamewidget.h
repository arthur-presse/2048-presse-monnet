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
    ~GameWidget(void);
    int getScore(void);
    void newGame(void);
    eventResult Up(void);
    eventResult Down(void);
    eventResult Left(void);
    eventResult Right(void);
    QString grid2string(void);
protected:
    virtual void paintEvent(QPaintEvent *);
    virtual void resizeEvent(QResizeEvent *);
private:
    QFont font;
    Grid grid;
    int score;
    bool win;
    bool forceFont;
    QTimer *timer;
    int iter = 0;
    bool add_item(void);
    bool check_lost(void);   
    eventResult action(Move *move);
    void adapt_police(int caseSize);
private slots:
    void timer_timeout(void);
};

#endif // GAMEWIDGET_H
