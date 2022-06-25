#include "Drop.hpp"
#include <basics/models/Square/Square.hpp>
#include <Badteroids/Ship/models/ShipModel.hpp>

Drop::Drop(float x, float y, float dy, size_t type) {
	this->VBO_v = BasicModels::Square::VBO_v;
	this->type = type;

	size_t color = VBOs::Color::WHITE;
	switch(type) {
	case Type::OXYGEN:
		color = VBOs::Color::LIGHTBLUE;
		break;
	case Type::SKILL:
		color = VBOs::Color::RED;
		break;
	}
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
	switch(type) {
	case Type::HYDROGEN:
		ship.addH();
		break;
	case Type::OXYGEN:
		ship.addO();
		break;
	case Type::SKILL:
		ship.addSkill();
		break;
	}

	return true;
}
