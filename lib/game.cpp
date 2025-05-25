#include "game.h"

Game::Game()
    : labyrinth(), player(18, 1, &labyrinth) // стартовая позиция игрока (пример)
{}

void Game::reset() {
    labyrinth.reset();
    player = Player(18, 1, &labyrinth);
}

bool Game::step(int direction) {
    return player.move(direction);
}

Player* Game::getPlayer() {
    return &player;
}

Labyrinth* Game::getLabyrinth() {
    return &labyrinth;
}

bool Game::isGameOver() const {
    return !player.isAlive();
}

bool Game::isWin() const {
    return player.isWin();
}