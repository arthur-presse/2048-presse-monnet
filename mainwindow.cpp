#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include <QMessageBox>
#include <QDebug>

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

bool MainWindow::eventFilter(QObject *object, QEvent *event){
    // on surcharge la méthode eventFilter pour récupérer les mouvements
    // haut, bas, gauche, droite.

    if (event->type() == QEvent::KeyPress){
        QKeyEvent* kev = static_cast<QKeyEvent*>(event);
        bool check_key = false;
        GameWidget::eventResult result;

        // on effectue un filtrage de cas pour récupérer les touches désirées
        switch(kev->key()) {
        case Qt::Key_Up:
            result = ui->Game->Up();
            check_key = true;
            break;
        case Qt::Key_Down:
            result = ui->Game->Down();
            check_key = true;
            break;
        case Qt::Key_Left:
            result = ui->Game->Left();
            check_key = true;
            break;
        case Qt::Key_Right:
            result = ui->Game->Right();
            check_key = true;
            break;
        default:
            break;
        }

         // Si la touche était correcte, on verifie si l'issue du jeu à changé
        if(check_key){
            ui->score_label->setText("Score : "+QString::number(ui->Game->getScore()));
            if(result == GameWidget::isWon){
                QMessageBox::information(this,"Victoire","Vous avez gagné ! Bravissimo !",QMessageBox::Ok);
                ui->Game->newGame();
                ui->score_label->setText("Score : "+QString::number(ui->Game->getScore()));
            }
            else if (result == GameWidget::isLost){
                QMessageBox::information(this,"Défaite","Vous avez perdu... Essayez encore !",QMessageBox::Ok);
                ui->Game->newGame();
                ui->score_label->setText("Score : "+QString::number(ui->Game->getScore()));
            }
            return true;
        }

    }
    return QObject::eventFilter(object,event);

}


void MainWindow::on_actionQuitter_triggered(){
    //fonction du bouton Quitter crée par le menu designer
    QApplication::quit();
}

void MainWindow::on_action4x4_cases_triggered()
{
    //fonction du bouton Nouvelle Partie crée par le menu designer
    COTE = 4;
    NbCase = COTE*COTE;

    ui->Game->newGame(COTE);
    ui->score_label->setText("Score : "+QString::number(ui->Game->getScore()));
}


void MainWindow::on_action5x5_cases_triggered()
{
    COTE = 5;
    NbCase = COTE*COTE;
    //fonction du bouton Nouvelle Partie crée par le menu designer
    ui->Game->newGame(COTE);
    ui->score_label->setText("Score : "+QString::number(ui->Game->getScore()));
}


void MainWindow::on_action6x6_cases_triggered()
{
    COTE = 6;
    NbCase = COTE*COTE;
    //fonction du bouton Nouvelle Partie crée par le menu designer
    ui->Game->newGame(COTE);
    ui->score_label->setText("Score : "+QString::number(ui->Game->getScore()));
}


void MainWindow::on_action7x7_cases_triggered()
{
    //fonction du bouton Nouvelle Partie crée par le menu designer
    COTE = 7;
    NbCase = COTE*COTE;
    ui->Game->newGame(COTE);
    ui->score_label->setText("Score : "+QString::number(ui->Game->getScore()));
}


void MainWindow::on_action8x8_cases_triggered()
{
    COTE = 8;
    NbCase = COTE*COTE;
    //fonction du bouton Nouvelle Partie crée par le menu designer
    ui->Game->newGame(COTE);
    ui->score_label->setText("Score : "+QString::number(ui->Game->getScore()));
}

