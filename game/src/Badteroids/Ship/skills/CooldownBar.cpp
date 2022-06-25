#include "Skill.hpp"

static glm::vec2* vertices = nullptr;
static Index* indices = nullptr;
static glm::vec3* colors = nullptr;

static const size_t global_vsize = 100;
static const size_t global_isize = 100;

static VBOid globalVBO_v = NULL_VBO;
static VBOid globalVBO_c = NULL_VBO;
static VBOid globalVBO_i = NULL_VBO;

static size_t cachedVal = 0;

void Skills::Skill::CooldownBar::upload() {
	vertices = new glm::vec2[global_vsize];
	indices = new Index[global_isize];
	colors = new glm::vec3[global_vsize];

	for(size_t i=0; i<global_vsize; ++i) {
		float y = (i - 50.0)/50;
		vertices[i].x = -1;
		vertices[i].y = y;

		indices[i] = i;
		colors[i] = {0, 0, 0};
	}

	globalVBO_v = VBOs::makeVertices(vertices, global_vsize);
	globalVBO_c = VBOs::makeColors(colors, global_vsize, true);
	globalVBO_i = VBOs::makeIndices(indices, global_isize);
}

Skills::Skill::CooldownBar::CooldownBar(size_t val) {
	if(val != cachedVal) {
		if(val == 100) {
			for(size_t i=0; i<global_vsize; ++i)
				colors[i] = {0, 1, 0};
		} else {
			for(size_t i=0; i<global_vsize; ++i) {
				if(i <= val)
					colors[i] = {1, 0, 0};
				else
					colors[i] = {0, 0, 0};
			}
		}

		VBOs::overwriteVBO(globalVBO_c, GL_ARRAY_BUFFER,
						   global_vsize * sizeof(glm::vec3), colors, true);
		cachedVal = val;
	}

	this->VBO_v = globalVBO_v;
	this->VBO_c = globalVBO_c;
	this->VBO_i = globalVBO_i;
	this->isize = global_isize;

	this->mode = GL_LINE_STRIP;
	this->lineWidth = 4;
}
