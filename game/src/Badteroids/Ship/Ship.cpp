#include "Ship.hpp"
#include <loop/objects.hpp>

Ship::Ship() {
	// For now, a dummy ship
	ShipModels::Dummy model;

	model.mulScalex(shipScalex);
	model.mulScaley(shipScaley);

	this->model = Objects::drawables.alloc(std::move(model));
}
