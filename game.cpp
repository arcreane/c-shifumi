#include "game.h"

Game::Game()
{

}

void Game::initGame(QString pseudo, int round){

    this->playerOne.name = pseudo;

    return;
}

QString Game::playGame(QString choice){
    if(choice == "rock"){
        return "égalité";
    }
    else if(choice == "paper"){
        return "victoire";
    }
    else if(choice == "scissors"){
        return "défaite";
    }
    else {
        return "y'a un problème !";
    }
}

void Game::endGame(){
    return;
}

void Game::saveGame(){
    return;
}
