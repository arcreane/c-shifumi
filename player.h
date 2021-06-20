#ifndef PLAYER_H
#define PLAYER_H

#include <QString>


class Player
{
public:
    Player();
    QString name;
    int matchPlayed;
    int nbWins;
    int nbLoses;

    void createPLayer();
    void updateScore();
    void chooseSign();
};

#endif // PLAYER_H
