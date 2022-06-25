#include "Stabilize.hpp"

static const glm::vec2 vertices[] = {
	glm::vec2(0, 0),
	glm::vec2(0, 1),
	glm::vec2(1, 0),
	glm::vec2(0, -1),
	glm::vec2(-1, 0)
};

static const Index indices[] = {0, 1, 0, 2, 0, 3, 0, 4};

static const glm::vec3 colors[] = {
	glm::vec3(1, 0, 0),
	glm::vec3(1, 1, 1),
	glm::vec3(1, 1, 1),
	glm::vec3(1, 1, 1),
	glm::vec3(1, 1, 1)
};

static const size_t global_vsize = sizeof(vertices) / sizeof(glm::vec2);
static const size_t global_isize = sizeof(indices) / sizeof(Index);

static VBOid globalVBO_v = NULL_VBO;
static VBOid globalVBO_c = NULL_VBO;
static VBOid globalVBO_i = NULL_VBO;

void Skills::Stabilize::Model::upload() {
	globalVBO_v = VBOs::makeVertices(vertices, global_vsize);
	globalVBO_c = VBOs::makeColors(colors, global_vsize);
	globalVBO_i = VBOs::makeIndices(indices, global_isize);
}

Skills::Stabilize::Model::Model() {
	this->VBO_v = globalVBO_v;
	this->VBO_c = globalVBO_c;
	this->VBO_i = globalVBO_i;
	this->isize = global_isize;

	this->mode = GL_LINES;
	this->lineWidth = 2;
}
