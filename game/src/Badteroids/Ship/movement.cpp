#include "Ship.hpp"
#include <Badteroids/RNG/RNG.hpp>

void Ship::_move(float dx, float dy) {
	size_t rngarea = (iam == LEFT_SHIP)
		? RNG::Area::LEFT_SHIP_DEVIATION
		: RNG::Area::RIGHT_SHIP_DEVIATION;
	float deviation = RNG::genf(rngarea, -maxDeviation, maxDeviation);

	if(dx)
		dx += deviation;
	else
		dy += deviation;

	auto& model = getModel();
	model.getInertia().vx += dx;
	model.getInertia().vy += dy;
}


void Ship::moveLeft()  { _move(-velocityPerPress, 0); }
void Ship::moveRight() { _move(+velocityPerPress, 0); }
void Ship::moveUp()    { _move(0, +velocityPerPress); }
void Ship::moveDown()  { _move(0, -velocityPerPress); }
