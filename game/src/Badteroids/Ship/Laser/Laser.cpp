#include "Laser.hpp"
#include <basics/models/Square/Square.hpp>

static glm::vec3 redSquare[] = {
	glm::vec3(1, 0, 0),
	glm::vec3(1, 0, 0),
	glm::vec3(1, 0, 0),
	glm::vec3(1, 0, 0)
};

static VBOid globalVBO_c = NULL_VBO;

void Laser::upload() {
	globalVBO_c = VBOs::makeColors(redSquare, BasicModels::Square::isize);
}

Laser::Laser(float x, float y) {
	this->VBO_v = BasicModels::Square::VBO_v;
	this->VBO_c = globalVBO_c;
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
