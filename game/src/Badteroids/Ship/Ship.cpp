#include "Ship.hpp"
#include <loop/objects.hpp>

Ship::Ship(bool iam_) {
	this->iam = iam_;

	// For now, a dummy ship
	ShipModels::Dummy model;

	model.mulScalex(shipScalex);
	model.mulScaley(shipScaley);

	// Alive region
	model.addx((iam == LEFT_SHIP) ? -0.5 : 0.5);

	// Start movement
	float startvx = velocityPerPress / 2;
	if(iam == RIGHT_SHIP)
		startvx *= -1;
	float startvy = -velocityPerPress / 2;

	model.getInertia().vx = startvx;
	model.getInertia().vy = startvy;

	// It could go in idrawables, but there would be no strict control over
	//   screen limits. It's different than other idrawables.
	this->model = std::move(model);

	// Let's precompute some values
	if(iam == LEFT_SHIP) {
		minx = -1;
		maxx = 0;
	} else {
		minx = 0;
		maxx = +1;
	}
	maxx -= shipScalex; // Same trick as in Drawables::outOfBounds
}

bool Ship::checkBounds() const {
	if(this->model.getx() < this->minx || this->model.gety() < this->miny)
		return false;
	if(this->model.getx() > this->maxx || this->model.gety() > this->maxy)
		return false;
	return true;
}
