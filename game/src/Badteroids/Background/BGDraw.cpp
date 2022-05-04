#include "Background.hpp"
#include <basics/models/Square/Square.hpp>
#include <cmath>

// It moves!
float pos = 0;
static glm::vec2 texcoords[] = {
	glm::vec2(0, 1+pos),
	glm::vec2(1, 1+pos),
	glm::vec2(1, 0+pos),
	glm::vec2(0, 0+pos)
};

static VBOid globalVBO_t = NULL_VBO;

void Background::BGDraw::upload() {
	globalVBO_t = VBOs::makeTextureCoords(texcoords, BasicModels::Square::vsize);
}

Background::BGDraw::BGDraw() {
	this->VBO_v = BasicModels::Square::VBO_v;
	this->VBO_i = BasicModels::Square::VBO_i;
	this->VBO_t = globalVBO_t;
	this->isize = BasicModels::Square::isize;
	this->mode = GL_TRIANGLES;
}

void Background::BGDraw::textick(float dt) {
	pos += this->velocity * dt;
	pos = fmod(pos, 2); // Lap at 2, just to avoid making the float big

	texcoords[0][1] = texcoords[1][1] = 1+pos;
	texcoords[2][1] = texcoords[3][1] = 0+pos;

	VBOs::overwriteVBO(this->VBO_t,
					   GL_ARRAY_BUFFER,
					   BasicModels::Square::vsize * sizeof(glm::vec2),
					   texcoords,
					   true);
}
