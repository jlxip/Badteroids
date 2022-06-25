#include "events.hpp"

extern Badteroids* game;

void lsLeft() {
	if(game->leftAlive() && !game->isPaused())
		game->getLeftShip().moveLeft();
}
void lsRight() {
	if(game->leftAlive() && !game->isPaused())
		game->getLeftShip().moveRight();
}
void lsUp() {
	if(game->leftAlive() && !game->isPaused())
		game->getLeftShip().moveUp();
}
void lsDown() {
	if(game->leftAlive() && !game->isPaused())
		game->getLeftShip().moveDown();
}


void rsLeft() {
	if(game->rightAlive() && !game->isPaused())
		game->getRightShip().moveLeft();
}
void rsRight() {
	if(game->rightAlive() && !game->isPaused())
		game->getRightShip().moveRight();
}
void rsUp() {
	if(game->rightAlive() && !game->isPaused())
		game->getRightShip().moveUp();
}
void rsDown() {
	if(game->rightAlive() && !game->isPaused())
		game->getRightShip().moveDown();
}




void lsShoot() {
	if(game->leftAlive() && !game->isPaused())
		game->getLeftShip().shoot();
}
void lsSkillFire() {
	if(game->leftAlive() && !game->isPaused())
		game->getLeftShip().skillFire();
}
void lsSkillLeft() {
	if(game->leftAlive() && !game->isPaused())
		game->getLeftShip().skillLeft();
}
void lsSkillRight() {
	if(game->leftAlive() && !game->isPaused())
		game->getLeftShip().skillRight();
}


void rsShoot() {
	if(game->rightAlive() && !game->isPaused())
		game->getRightShip().shoot();
}
void rsSkillFire() {
	if(game->rightAlive() && !game->isPaused())
		game->getRightShip().skillFire();
}
void rsSkillLeft() {
	if(game->rightAlive() && !game->isPaused())
		game->getRightShip().skillLeft();
}
void rsSkillRight() {
	if(game->rightAlive() && !game->isPaused())
		game->getRightShip().skillRight();
}




void _menuUp() { if(game->isInMenu()) game->getMenu().move(0); }
void _menuDown() { if(game->isInMenu()) game->getMenu().move(1); }
void _menuLeft() { if(game->isInMenu()) game->getMenu().move(2); }
void _menuRight() { if(game->isInMenu()) game->getMenu().move(3); }
void _menuEnter() { if(game->isInMenu()) game->getMenu().move(99); }

void _pause() { if(game->isPlaying()) game->switchPause(); }
