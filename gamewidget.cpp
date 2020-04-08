#include "gamewidget.h"

GameWidget::GameWidget(QWidget *parent) : QWidget(parent)
{
    srand(time(NULL)); //initialisation de la fonction rand()
    newGame(); //on crée une nouvelle partie
}

void GameWidget::newGame(void) {
    // initialisation du score et de la grille des cases
    score = 0;
    memset(grid, 0, NbCase * 3);

    //ajout de deux nouvelles cases dans la grille pour commencer
    add_item();
    add_item();

}

bool GameWidget::add_item(void){
    // fonction qui ajoute une nouvelle case dans la grille
    // et renvoie un booleen indiquant si l'action a réussi ou échoué
    int last_empty_case = -1;
    int empty_grid[NbCase];

    // On récupère la liste des cases vides
    for(int i=0;i<NbCase;i++){
        if(grid[i].value == 0) {
            empty_grid[last_empty_case+1] = i;
            last_empty_case = last_empty_case + 1;
        }
    };

    // On ajoute une nouvelle tuile dans une case au hasard parmi les cases libres
    if(last_empty_case != -1){
        int new_case_id = rand() % (last_empty_case + 1);
        int new_case_value = 2 * (rand() % 2 + 1); //peut valoir 2 ou 4
        grid[new_case_id].value = new_case_value;
        grid[new_case_id].newvalue = true;

        score = qMax(score,grid[new_case_id].value);

        return true; // on a pu ajouter une nouvelle case
    }

    return false;
}
