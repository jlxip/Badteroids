#include "Laser.hpp"
#include <basics/models/Square/Square.hpp>

Laser::Laser(float x, float y) {
	this->VBO_v = BasicModels::Square::VBO_v;
	this->VBO_c = VBOs::requestRedVBO(4);
	this->VBO_i = BasicModels::Square::VBO_i;
	this->isize = BasicModels::Square::isize;

	this->mode = BasicModels::Square::mode;

	this->scalex = Laser::sx;
	this->scaley = Laser::sy;
	this->x = x;
	this->y = y;

	this->inertia.vx = Laser::thevx;
	this->inertia.vy = Laser::thevy;
}
