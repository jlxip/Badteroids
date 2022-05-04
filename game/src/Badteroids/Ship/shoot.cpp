#include "Ship.hpp"

void Ship::shoot() {
	// Clearly, X is ship's
	float x = this->model.getx();
	// Y is displaced to the top
	float y = this->model.gety() + Laser::sy;

	Objects::idrawables.alloc(Laser(x, y));

	// Blowback
	this->model.getInertia().vy -= shootBlowback;
}
