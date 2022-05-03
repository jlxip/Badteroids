#include "Ship.hpp"
#include <loop/objects.hpp>

Ship::Ship(bool iam_) {
	this->iam = iam_;

	// For now, a dummy ship
	ShipModels::Dummy model;

	model.mulScalex(shipScalex);
	model.mulScaley(shipScaley);

	// Start movement
	float startvx = velocityPerPress / 2;
	if(iam == RIGHT_SHIP)
		startvx *= -1;
	float startvy = -velocityPerPress / 2;

	model.getInertia().vx = startvx;
	model.getInertia().vy = startvy;

	// A ship has inertia, so let's go with idrawables
	this->model = Objects::idrawables.alloc(std::move(model));
}
