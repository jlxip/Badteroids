#include "Bar.hpp"
#include <basics/models/Square/Square.hpp>

Bar::Bar() {
	this->VBO_v = BasicModels::Square::VBO_v;
	this->VBO_c = VBOs::requestColor(VBOs::Color::WHITE, 4);
	this->VBO_i = BasicModels::Square::VBO_i;
	this->isize = BasicModels::Square::isize;

	this->mode = BasicModels::Square::mode;

	this->scalex = Bar::barScaley;
}
