#ifndef GAME_H
#define GAME_H

#include "labyrinth.h"
#include "player.h"

class Game {
public:
    Game();
    void reset();
    bool step(int direction); // обработка хода игрока
    Player* getPlayer();
    Labyrinth* getLabyrinth();
    bool isGameOver() const;
    bool isWin() const;
private:
    Labyrinth labyrinth;
    Player player;
};

#endif