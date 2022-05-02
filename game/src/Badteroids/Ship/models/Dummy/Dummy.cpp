#include "Dummy.hpp"

static const glm::vec2 vertices[] = {
	glm::vec2(0, 1),
	glm::vec2(-1, -1),
	glm::vec2(0, -0.5),
	glm::vec2(1, -1)
};

static const Index indices[] = {0, 1, 2, 3, 0, 2};

static const size_t global_vsize = sizeof(vertices) / sizeof(glm::vec2);
static const size_t global_isize = sizeof(indices) / sizeof(Index);

static VBOid globalVBO_v = NULL_VBO;
static VBOid globalVBO_i = NULL_VBO;

void ShipModels::Dummy::upload() {
	globalVBO_v = VBOs::makeVertices(vertices, global_vsize);
	globalVBO_i = VBOs::makeIndices(indices, global_isize);
}

ShipModels::Dummy::Dummy() {
	this->VBO_v = globalVBO_v;
	this->VBO_i = globalVBO_i;
	this->isize = global_isize;
}
