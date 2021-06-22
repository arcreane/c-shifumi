#include "game.h"

Game::Game()
{

}

void Game::initGame(QString pseudo, int round){

    this->playerOne.name = pseudo;
    maxRound = round;

    return;
}

std::vector<std::string> Game::playGame(int userChoice){

    static std::vector<std::string> result (2);
    int iaChoice = rand() % 3;
    int rules[3][2] = {{2, 1}, {0,2}, {1, 0}};


    if(userChoice == iaChoice){
        result[0] = "égalité";
        result[1] = std::to_string(iaChoice);
    }
    else if(rules[userChoice][0] == iaChoice){
        result[0] = "victoire";
        result[1] = std::to_string(iaChoice);
        this->playerOne.nbWins++;
    }
    else if(rules[userChoice][1] == iaChoice){
        result[0] = "défaite";
        result[1] = std::to_string(iaChoice);
        this->playerOne.nbLoses++;
    }
    return result;
}

void Game::endGame(){
    return;
}

void Game::saveGame(){
    return;
}
