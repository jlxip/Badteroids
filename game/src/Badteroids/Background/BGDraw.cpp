#include "Background.hpp"
#include <cmath>

static const glm::vec2 vertices[] = {
	glm::vec2(-1, +1),
	glm::vec2(+1, +1),
	glm::vec2(+1, -1),
	glm::vec2(-1, -1)
};

static const Index indices[] = {
	0, 1, 3,
	1, 2, 3
};

// It moves!
float pos = 0;
static glm::vec2 texcoords[] = {
	glm::vec2(0, 1+pos),
	glm::vec2(1, 1+pos),
	glm::vec2(1, 0+pos),
	glm::vec2(0, 0+pos)
};

static const size_t global_vsize = sizeof(vertices) / sizeof(glm::vec2);
static const size_t global_isize = sizeof(indices) / sizeof(Index);

static VBOid globalVBO_v = NULL_VBO;
static VBOid globalVBO_i = NULL_VBO;
static VBOid globalVBO_t = NULL_VBO;

void Background::BGDraw::upload() {
	globalVBO_v = VBOs::makeVertices(vertices, global_vsize);
	globalVBO_i = VBOs::makeIndices(indices, global_isize);
	globalVBO_t = VBOs::makeTextureCoords(texcoords, global_vsize);
}

Background::BGDraw::BGDraw() {
	this->VBO_v = globalVBO_v;
	this->VBO_i = globalVBO_i;
	this->VBO_t = globalVBO_t;
	this->isize = global_isize;
	this->mode = GL_TRIANGLES;
}

void Background::BGDraw::textick(float dt) {
	pos += this->velocity * dt;
	pos = fmod(pos, 2); // Lap at 2, just to avoid making the float big

	texcoords[0][1] = texcoords[1][1] = 1+pos;
	texcoords[2][1] = texcoords[3][1] = 0+pos;

	VBOs::overwriteVBO(this->VBO_t,
					   GL_ARRAY_BUFFER,
					   global_vsize * sizeof(glm::vec2),
					   texcoords,
					   true);
}
