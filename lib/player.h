#ifndef PLAYER_H
#define PLAYER_H

#include <Arduino.h>
#include "labyrinth.h"

class Player {
public:
    Player(int startX, int startY, Labyrinth* labyrinth);

    int getX() const;
    int getY() const;
    int getScore() const;

    // direction: 1 — вверх, 2 — вниз, 3 — влево, 4 — вправо
    bool move(int direction);

    bool isAlive() const;
    bool isWin() const;

private:
    int x, y;
    int score;
    bool alive;
    bool win;
    Labyrinth* lab;
};

#endif