#include "game.h"

Game::Game()
{

}

void Game::initGame(QString pseudo, int round){

    this->playerOne.name = pseudo;
    maxRound = round;

    return;
}

QString * Game::playGame(int userChoice){

    static QString result[2];
    while(maxRound!=this->playerOne.nbWins || maxRound!=this->playerTwo.nbWins){
        int iaChoice = rand() % 3;
        int rules[3][2] = {{2, 1}, {0,2}, {1, 0}};


        if(userChoice == iaChoice){
            result[0] = "égalité";
            result[1] = QString::number(iaChoice);
        }
        else if(rules[userChoice][0] == iaChoice){
            result[0] = "victoire";
            result[1] = QString::number(iaChoice);
        }
        else if(rules[userChoice][1] == iaChoice){
            result[0] = "défaite";
            result[1] = QString::number(iaChoice);
        }
    }
    return result;
}

void Game::endGame(){
    return;
}

void Game::saveGame(){
    return;
}
