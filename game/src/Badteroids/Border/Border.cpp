#include "Border.hpp"
#include <basics/models/Square/Square.hpp>

Border::Border(bool horizontal, bool first) {
	this->VBO_v = BasicModels::Square::VBO_v;
	this->VBO_c = VBOs::requestColor(VBOs::Color::BLACK, 4);
	this->VBO_i = BasicModels::Square::VBO_i;
	this->isize = BasicModels::Square::isize;

	this->mode = BasicModels::Square::mode;

	if(horizontal) {
		this->scalex = Border::borderScale;
		this->x = -1-scalex/2;
		if(!first)
			this->x *= -1;
	} else {
		this->scaley = Border::borderScale;
		this->y = +1+scaley/2;
		if(!first)
			this->y *= -1;
	}
}
