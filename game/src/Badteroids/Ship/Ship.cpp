#include "Ship.hpp"
#include <loop/objects.hpp>
#include "models/all.hpp"
#include "skills/skills.hpp"
#include "ShipTimedEvent.hpp"
#include <Badteroids/Badteroids.hpp>

extern Badteroids* game;

Ship::Ship(bool iam_) {
	this->iam = iam_;
}

void Ship::init() {
	// For now, a dummy ship
	auto* model = new ShipModels::Dummy;
	model->setParent(this);

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

	maxDeviation = velocityPerPress * 0.05;

	// Resources
	resources.h = resources.o = 100;

	// Skills
	for(auto x : skills)
		delete x;
	skills.clear();
	skills.push_back(dynamic_cast<Skills::Skill*>(new Skills::Stabilize));
	skills.push_back(dynamic_cast<Skills::Skill*>(new Skills::Destabilize));

	for(auto x : skills)
		x->setiam(iam);
}

void Ship::tick() {
	// Check if any TimedEvent deadlines have passed
	auto it = TimedEvents::events.begin();
	while(it != TimedEvents::events.end()) {
		TimedEvents::TimedEvent* e = *it;
		if(e->deadline > game->getInGameTime())
			break; // That's it, because it's sorted

		if(e->isShip) {
			// I've got this
			auto* se = (TimedEvents::ShipRelated*)e;

			if(se->mulDeviation)
				maxDeviation /= se->mulDeviation;

			delete se;
			it = TimedEvents::events.erase(it);
		} else {
			// Not my cup of tea
			++it;
		}
	}
}
