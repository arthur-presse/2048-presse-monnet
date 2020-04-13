#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    bool eventFilter(QObject *object, QEvent *event);

private slots:
    void on_actionQuitter_triggered();

    void on_action4x4_cases_triggered();
    void on_action5x5_cases_triggered();
    void on_action6x6_cases_triggered();
    void on_action7x7_cases_triggered();
    void on_action8x8_cases_triggered();
private:
    Ui::MainWindow *ui;
    int NbCase = 16;
    int COTE = 4;
};
#endif // MAINWINDOW_H
