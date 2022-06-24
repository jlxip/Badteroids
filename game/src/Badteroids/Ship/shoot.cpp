#include "Ship.hpp"

void Ship::shoot() {
	auto& model = getModel();

	// Clearly, X is ship's
	float x = model.getx();
	// Y is displaced to the top
	float y = model.gety() + Laser::sy;

	Laser* laser = new Laser(x, y);
	Objects::cidrawablesp.alloc(dynamic_cast<Drawable*>(laser));
}
