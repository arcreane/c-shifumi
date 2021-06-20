#ifndef GAME_H
#define GAME_H

#include "player.h"

class Game
{
public:
    Game();
    Player playerOne;
    Player playerTwo;
    bool isSolo;
    int currentRound;
    int maxRound;
    float time;

    void initGame(QString pseudo, int round);
    void playGame();
    void endGame();
    void saveGame();

};

#endif // GAME_H
