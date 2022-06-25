#include "Skill.hpp"
#include <Badteroids/Badteroids.hpp>

extern Badteroids* game;

void Skills::Skill::setHUDposition(size_t pos) {
	model.sety(0.6);

	float x = -0.8;
	float scale = .4;

	if(iam)
		x = 0.8; // Right ship;

	switch(pos) {
	case 0:
		x -= .1;
		scale -= .1;
		break;
	case 2:
		x += .1;
		scale -= .1;
		break;
	}

	model.setx(x);

	model.setScalex(scale / ARX);
	model.setScaley(scale / ARY);
}

float Skills::Skill::timeUntilCooldown() {
	float cooldown = getCooldown();

	float past = game->getInGameTime() - lastShot;
	if(past > cooldown)
		return 0;

	return 1 - past/cooldown;
}

#include <Badteroids/Badteroids.hpp>
extern Badteroids* game;

void Skills::Skill::takeResources() {
	Ship* ship = &(game->getLeftShip());
	if(iam)
		ship = &(game->getRightShip());

	ship->addH(-expenseH());
	ship->addO(-expenseO());

	lastShot = game->getInGameTime();
}

bool Skills::Skill::canFire() {
	if(timeUntilCooldown())
		return false;

	Ship* ship = &(game->getLeftShip());
	if(iam)
		ship = &(game->getRightShip());

	if(ship->getH() < expenseH())
		return false;
	if(ship->getO() < expenseO())
		return false;

	return true;
}

void Skills::Skill::draw() {
	// Draw model
	model.draw();

	// Draw cooldown indicator
	CooldownBar bar(100 * (1 - timeUntilCooldown()));
	bar.sety(model.gety());
	bar.setx(model.getx());
	bar.setScalex(model.getScalex());
	bar.setScaley(model.getScaley());
	bar.draw();
}
