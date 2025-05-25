#include "player.h"

// Конструктор
Player::Player(int startX, int startY, Labyrinth* labyrinth)
    : x(startX), y(startY), score(0), alive(true), win(false), lab(labyrinth) {}

    // Геттеры
int Player::getX() const { return x; }
int Player::getY() const { return y; }
int Player::getScore() const { return score; }
bool Player::isAlive() const { return alive; }
bool Player::isWin() const { return win; }

// Метод для перемещения игрока
bool Player::move(int direction) {
    if (!alive || win) return false;

    int newX = x, newY = y;
    if (direction == 1) newX--;      // вверх 
    else if (direction == 2) newX++; // вниз
    else if (direction == 3) newY--; // влево
    else if (direction == 4) newY++; // вправо

    if (lab->isWall(newX, newY)) return false;

    x = newX;
    y = newY;

    if (lab->isCoin(x, y)) {
        score++;
        lab->removeCoin(x, y);
    }
    if (lab->isEnemy(x, y)) {
        alive = false;
    }
    if (lab->isFinish(x, y)) {
        win = true;
    }
    return true;
}