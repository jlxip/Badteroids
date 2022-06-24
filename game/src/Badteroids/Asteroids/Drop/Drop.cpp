#include "Drop.hpp"
#include <basics/models/Square/Square.hpp>
#include <Badteroids/Ship/models/ShipModel.hpp>

Drop::Drop(float x, float y, float dy, size_t type) {
	this->VBO_v = BasicModels::Square::VBO_v;

	size_t color = type == Type::HYDROGEN ? VBOs::Color::WHITE : VBOs::Color::LIGHTBLUE;
	this->VBO_c = VBOs::requestColor(color, 4);

	this->VBO_i = BasicModels::Square::VBO_i;
	this->isize = BasicModels::Square::isize;

	this->mode = BasicModels::Square::mode;

	this->scalex = SIZE / ARX;
	this->scaley = SIZE / ARY;

	this->x = x;
	this->y = y;

	this->inertia.vy = dy;
}

bool Drop::collisioned(Drawable* other) {
	auto* model = dynamic_cast<ShipModels::ShipModel*>(other);
	if(model == nullptr)
		return false;

	Ship& ship = model->getParent();
	if(type == Type::HYDROGEN)
		ship.addH();
	else
		ship.addO();

	return true;
}
