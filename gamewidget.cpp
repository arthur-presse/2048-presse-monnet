#include "gamewidget.h"

GameWidget::GameWidget(QWidget *parent) : QWidget(parent)
{
    srand(time(NULL)); //initialisation de la fonction rand()
    newGame(); //on crée une nouvelle partie
};

void GameWidget::newGame(void) {
    // initialisation du score et de la grille des cases
    score = 0;
    memset(grid, 0, NbCase * 3);

    //ajout de deux nouvelles cases dans la grille pour commencer
    add_item();
    add_item();

};

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
};

GameWidget::eventResult GameWidget::action(Move *move){
    // Cette fonction effectue le mouvement demandé et renvoie une information sur
    // l'état de la partie (gagné, perdu, a bougé, n'a pas bougé).

    //On génère le déplacement et on récupère la réussite ou non
    bool hasMoved = move->doMove(grid, score);

    //Etapes de vérification
    if(hasMoved){
        //en cas de mouvement réussi, on ajoute une case
        add_item();
        //vérification du score
        if(score == 2048){
            win = true;
            return isWon;
        } else {
            return isMoving;
        };
    //en cas d'échec du mouvement
    } else {
        //soit on a perdu, soit la demande n'a pas abouti (rien n'a bougé)
        return check_lost() ? isLost : isNone;
    }
}

bool GameWidget::check_lost(){
    // Cette fonction verifie si la partie est perdue
    // Schéma de l'algo :
    //  - on vérifie la présence de cases vides
    //  - on vérifie la possibilité de fusions horizontales
    //  - on vérifie la possibilité de fusions verticales

    for(int i=0;i<NbCase;i++){
        if(grid[i].value == 0){
            return false;
        };
    };

    for(int i=0;i<NbCase;i++){
        // verification des fusions horizontale
        if(i % COTE != COTE - 1){
            if (grid[i].value == grid[i+1].value){
                return false;
            }
        }
        //vérification verticale
        if(i / COTE != COTE - 1){
            if (grid[i].value == grid[i+1].value){
                return false;
            }
        }
    }
    return true;
}

GameWidget::eventResult GameWidget::Up(){
    //appelé quand le bouton pressé est "haut"
    MoveUp move;
    return action(&move);
}

GameWidget::eventResult GameWidget::Down(){
    //appelé quand le bouton pressé est "bas"
    MoveDown move;
    return action(&move);
}

GameWidget::eventResult GameWidget::Left(){
    //appelé quand le bouton pressé est "gauche"
    MoveLeft move;
    return action(&move);
}

GameWidget::eventResult GameWidget::Right(){
    //appelé quand le bouton pressé est "droite"
    MoveRight move;
    return action(&move);
}

int GameWidget::getScore(){
    return score;
}
