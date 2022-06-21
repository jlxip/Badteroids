#include "events.hpp"

extern Badteroids* game;

void lsLeft() { if(game->getShowLeft()) game->getLeftShip().moveLeft(); }
void lsRight() { if(game->getShowLeft()) game->getLeftShip().moveRight(); }
void lsUp() { if(game->getShowLeft()) game->getLeftShip().moveUp(); }
void lsDown() { if(game->getShowLeft()) game->getLeftShip().moveDown(); }

void rsLeft() { if(game->getShowRight()) game->getRightShip().moveLeft(); }
void rsRight() { if(game->getShowRight()) game->getRightShip().moveRight(); }
void rsUp() { if(game->getShowRight()) game->getRightShip().moveUp(); }
void rsDown() { if(game->getShowRight()) game->getRightShip().moveDown(); }

void lsShoot() { if(game->getShowLeft()) game->getLeftShip().shoot(); }
void rsShoot() { if(game->getShowRight()) game->getRightShip().shoot(); }

void _menuUp() { if(game->isInMenu()) game->getMenu().move(0); }
void _menuDown() { if(game->isInMenu()) game->getMenu().move(1); }
void _menuLeft() { if(game->isInMenu()) game->getMenu().move(2); }
void _menuRight() { if(game->isInMenu()) game->getMenu().move(3); }
void _menuEnter() { if(game->isInMenu()) game->getMenu().move(99); }
