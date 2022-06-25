#include "Ship.hpp"
#include <Badteroids/RNG/RNG.hpp>
#include <cmath>

void Ship::_move(float dx, float dy) {
	size_t rngarea = (iam == LEFT_SHIP)
		? RNG::Area::LEFT_SHIP_DEVIATION
		: RNG::Area::RIGHT_SHIP_DEVIATION;
	float deviation = RNG::genf(rngarea, 0, maxDeviation);

	if(dx > 0)
		dx += deviation;
	else if(dx < 0)
		dx -= deviation;
	else if(dy > 0)
		dy += deviation;
	else
		dy -= deviation;

	// Are ther resources?
	float usedH = HYDROGEN_BURN * std::abs(dx + dy);
	float usedO = OXYGEN_PER_HYDROGEN * usedH;

	if(resources.h < usedH || resources.o < usedO)
		return; // Oops, you ran out

	// Perform movement
	auto& model = getModel();
	model.getInertia().vx += dx;
	model.getInertia().vy += dy;

	// Use resources
	resources.h -= usedH;
	resources.o -= usedO;
}

void Ship::moveLeft()  { _move(-velocityPerPress, 0); }
void Ship::moveRight() { _move(+velocityPerPress, 0); }
void Ship::moveUp()    { _move(0, +velocityPerPress); }
void Ship::moveDown()  { _move(0, -velocityPerPress); }
