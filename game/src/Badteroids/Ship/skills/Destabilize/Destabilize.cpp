#include "Destabilize.hpp"
#include <Badteroids/Badteroids.hpp>
#include <Badteroids/Ship/ShipTimedEvent.hpp>

extern Badteroids* game;

Skills::Destabilize::Destabilize() {
	model = std::move(Model());
}

void Skills::Destabilize::fire() {
	// Opposite ship
	Ship* ship = &(game->getRightShip());
	if(iam)
		ship = &(game->getLeftShip());

	ship->destabilize(factor);

	// Start timer
	auto* te = new TimedEvents::ShipRelated;
	te->base.deadline = game->getInGameTime() + duration;
	te->mulDeviation = factor;
	TimedEvents::events.insert((TimedEvents::TimedEvent*)te);

	takeResources();
}
