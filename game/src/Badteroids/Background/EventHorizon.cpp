#include "EventHorizon.hpp"
#include <basics/models/Square/Square.hpp>

static constexpr float START_Y = 2;

EventHorizon::EventHorizon() {
	this->VBO_v = BasicModels::Square::VBO_v;
	this->VBO_c = VBOs::requestColor(VBOs::Color::BLACK, 4);
	this->VBO_i = BasicModels::Square::VBO_i;
	this->isize = BasicModels::Square::isize;

	this->mode = BasicModels::Square::mode;

	this->y = START_Y;
}

void EventHorizon::customTick(Time dt) {
	if(this->y <= 0) {
		this->y = 0;
		return;
	}

	this->y -= velocity * dt;
}

void EventHorizon::reset() {
	this->y = START_Y;
}
