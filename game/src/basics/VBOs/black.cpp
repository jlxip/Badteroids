#include "VBOs.hpp"

// Go read "green.cpp" first

static VBOid blackVBO = NULL_VBO;
static size_t maxvertices = 0;
static const glm::vec3 black(0.0, 0.0, 0.0);

static glm::vec3* local = nullptr;

VBOid VBOs::requestBlackVBO(size_t vertices) {
	if(!local) {
		local = (glm::vec3*)malloc(vertices * sizeof(glm::vec3));
		for(size_t i=0; i<vertices; ++i)
			local[i] = black;
		maxvertices = vertices;

		blackVBO = makeColors(local, vertices);
	} else if(vertices > maxvertices) {
		// Need more!
		local = (glm::vec3*)realloc(local, vertices * sizeof(glm::vec3));
		for(size_t i=maxvertices; i<vertices; ++i)
			local[i] = black;

		glBindBuffer(GL_ARRAY_BUFFER, blackVBO); // Attach
		glBufferData(GL_ARRAY_BUFFER, maxvertices, local, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, NULL_VBO); // Deattach
	}

	return blackVBO;
}
