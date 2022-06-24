#include "Ship.hpp"
#include <loop/objects.hpp>

Ship::Ship(bool iam_) {
	this->iam = iam_;
}

void Ship::init() {
	// For now, a dummy ship
	auto* model = new ShipModels::Dummy;

	model->mulScalex(shipScalex);
	model->mulScaley(shipScaley);

	// It could go in idrawables, but there would be no strict control over
	//   screen limits. It's different than other idrawables.
	obj = Objects::cidrawablesp.alloc(dynamic_cast<Drawable*>(model));

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

void Ship::reset() {
	if(!alive())
		init();

	// Position
	auto& model = getModel();
	model.resetxy();
	model.addx((iam == LEFT_SHIP) ? -0.5 : 0.5);

	// Velocity
	float startvx = velocityPerPress / 2;
	if(iam == RIGHT_SHIP)
		startvx *= -1;
	float startvy = -velocityPerPress / 2;

	model.getInertia().vx = startvx;
	model.getInertia().vy = startvy;
}
