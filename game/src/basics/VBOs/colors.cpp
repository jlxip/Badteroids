#include "VBOs.hpp"
#include <unordered_map>

// A lot of objects in Badteroids are the same color
// Why not have just one VBO_c for each of them?

static const glm::vec3 actualColors[] = {
	{1, 1, 1},
	{0, 0, 0},
	{1, 0, 0},
	{0, 1, 0},
	{0.5, 0.5, 1},
};

struct ColorInfo {
	VBOid vbo = NULL_VBO;
	size_t maxv = 0;

	// Have to save it somewhere
	glm::vec3* buffer = nullptr;
};

static std::unordered_map<size_t, ColorInfo> colors;

VBOid VBOs::requestColor(size_t color, size_t vertices) {
	ColorInfo& info = colors[color];

	if(!info.buffer) {
		info.buffer = (glm::vec3*)malloc(vertices * sizeof(glm::vec3));
		for(size_t i=0; i<vertices; ++i)
			info.buffer[i] = actualColors[color];

		info.maxv = vertices;
		info.vbo = makeColors(info.buffer, vertices);
	} else if(vertices > info.maxv) {
		// Need more!
		info.buffer = (glm::vec3*)realloc(info.buffer, vertices * sizeof(glm::vec3));
		for(size_t i=info.maxv; i<vertices; ++i)
			info.buffer[i] = actualColors[color];

		info.maxv = vertices;
		VBOs::overwriteVBO(info.vbo, GL_ARRAY_BUFFER,
						   vertices * sizeof(glm::vec3), info.buffer, false);
	}

	return info.vbo;
}
