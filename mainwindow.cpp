#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    installEventFilter(this);
    ui->score_label->setText("Score : "+QString::number(ui->Game->getScore()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
