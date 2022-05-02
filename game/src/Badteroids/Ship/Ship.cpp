#include "Ship.hpp"
#include <loop/objects.hpp>

Ship::Ship() {
	// For now, a dummy ship
	ShipModels::Dummy model;
	ObjID id = Objects::drawables.alloc(std::move(model));
	std::cout << "ID is: " << id << std::endl;
}
