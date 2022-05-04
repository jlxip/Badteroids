#include "Ship.hpp"

void Ship::shoot() {
	Drawable& me = Objects::idrawables.get(model);

	// Clearly, X is ship's
	float x = me.getx();
	// Y is displaced to the top
	float y = me.gety() + Laser::sy;

	Objects::idrawables.alloc(Laser(x, y));

	// Blowback
	me.getInertia().vy -= shootBlowback;
}
