#ifndef LABYRINTH_H
#define LABYRINTH_H

#include <Arduino.h>

#define ROWS 20
#define COLS 20

class Labyrinth {
public:
    Labyrinth();
    bool isWall(int x, int y) const;
    bool isCoin(int x, int y) const;
    void removeCoin(int x, int y);
    void reset(); // сбросить лабиринт к начальному состоянию

private:
    int map[ROWS][COLS];
    void initMap();
};

#endif