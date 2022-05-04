#include "Ship.hpp"

void Ship::shoot() {
	Drawable& drawable = Objects::idrawables.get(model);

	// Clearly, X is ship's
	float x = drawable.getx();
	// Y is displaced to the top
	float y = drawable.gety() + Laser::sy;

	Objects::idrawables.alloc(Laser(x, y));
}
