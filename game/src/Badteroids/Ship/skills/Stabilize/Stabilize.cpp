#include "Stabilize.hpp"
#include <Badteroids/Badteroids.hpp>

extern Badteroids* game;

Skills::Stabilize::Stabilize() {
	model = std::move(Model());
}

void Skills::Stabilize::fire() {
	Ship* ship = &(game->getLeftShip());
	if(iam)
		ship = &(game->getRightShip());

	auto& inertia = ship->getModel().getInertia();
	inertia.vx = inertia.vy = 0.01;

	takeResources();
}
