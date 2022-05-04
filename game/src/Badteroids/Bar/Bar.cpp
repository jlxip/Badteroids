#include "Bar.hpp"
#include <basics/models/Square/Square.hpp>

static glm::vec3 whiteSquare[] = {
	glm::vec3(1, 1, 1),
	glm::vec3(1, 1, 1),
	glm::vec3(1, 1, 1),
	glm::vec3(1, 1, 1)
};

static VBOid globalVBO_c = NULL_VBO;

void Bar::upload() {
	globalVBO_c = VBOs::makeColors(whiteSquare, BasicModels::Square::isize);
}

Bar::Bar() {
	this->VBO_v = BasicModels::Square::VBO_v;
	this->VBO_c = globalVBO_c;
	this->VBO_i = BasicModels::Square::VBO_i;
	this->isize = BasicModels::Square::isize;

	this->mode = BasicModels::Square::mode;

	this->scalex = Bar::barScaley;
}
