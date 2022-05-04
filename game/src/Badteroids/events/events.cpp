#include "events.hpp"

extern Badteroids* game;

void lsLeft() { game->getLeftShip().moveLeft(); }
void lsRight() { game->getLeftShip().moveRight(); }
void lsUp() { game->getLeftShip().moveUp(); }
void lsDown() { game->getLeftShip().moveDown(); }

void lsShoot() { game->getLeftShip().shoot(); }
