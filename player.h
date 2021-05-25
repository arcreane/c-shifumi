#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

class Player
{
public:
    Player();
    std::string name;
    int matchPlayed;
    int nbWins;
    int nbLoses;

    void createPLayer();
    void updateScore();
    void chooseSign();
};

#endif // PLAYER_H
