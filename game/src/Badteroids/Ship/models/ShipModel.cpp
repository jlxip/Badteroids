#include "ShipModel.hpp"
#include <Badteroids/Badteroids.hpp>

extern Badteroids* game;

bool ShipModels::ShipModel::collisioned(Drawable* other) {
	if(game->isGodMode())
		return false;

	if(instanceof<Laser>(other))
		return false;
	if(instanceof<Drop>(other))
		return false;

	game->win(!parent->getiam());
	return true;
}
