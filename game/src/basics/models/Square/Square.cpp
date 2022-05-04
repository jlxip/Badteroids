#include "Square.hpp"

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

VBOid BasicModels::Square::VBO_v = NULL_VBO;
VBOid BasicModels::Square::VBO_i = NULL_VBO;

void BasicModels::Square::upload() {
	VBO_v = VBOs::makeVertices(vertices, vsize);
	VBO_i = VBOs::makeIndices(indices, isize);
}
