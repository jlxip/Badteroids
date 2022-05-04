#include "events.hpp"

extern Badteroids* game;

void lsLeft() { game->getLeftShip().moveLeft(); }
void lsRight() { game->getLeftShip().moveRight(); }
void lsUp() { game->getLeftShip().moveUp(); }
void lsDown() { game->getLeftShip().moveDown(); }

void rsLeft() { game->getRightShip().moveLeft(); }
void rsRight() { game->getRightShip().moveRight(); }
void rsUp() { game->getRightShip().moveUp(); }
void rsDown() { game->getRightShip().moveDown(); }

void lsShoot() { game->getLeftShip().shoot(); }
void rsShoot() { game->getRightShip().shoot(); }
