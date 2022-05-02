#ifndef GREEN_HPP
#define GREEN_HPP

#include "VBOs.hpp"

// A lot of objects in Badteroids are "just green"™
// Why not have one VBO_c for all of them?

static VBOid greenVBO = NULL_VBO;
static size_t maxvertices = 0;
static const glm::vec3 green(0.0, 1.0, 0.0); // Some nice green right there

// Have to save this since apparently glBufferData is asynchronous :^)
static glm::vec3* local = nullptr;

VBOid VBOs::requestGreenVBO(size_t vertices) {
	if(!local) {
		local = (glm::vec3*)malloc(vertices * sizeof(glm::vec3));
		for(size_t i=0; i<vertices; ++i)
			local[i] = green;
		maxvertices = vertices;

		greenVBO = makeColors(local, vertices);
	} else if(vertices > maxvertices) {
		// Need more!
		local = (glm::vec3*)realloc(local, vertices * sizeof(glm::vec3));
		for(size_t i=maxvertices; i<vertices; ++i)
			local[i] = green;

		glBindBuffer(GL_ARRAY_BUFFER, greenVBO); // Attach
		glBufferData(GL_ARRAY_BUFFER, maxvertices, local, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, NULL_VBO); // Deattach
	}

	return greenVBO;
}

#endif
