#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <common.hpp>
#include <vector>


// Basic drawable object
// Set of triangles

typedef uint32_t VBOid;
const VBOid NULL_VBO = 0;
#define VBO_NULL_OFFSET 0

typedef uint32_t Index;

class Drawable {
private:
	VBOid VBO_v = NULL_VBO; // Vertices
	VBOid VBO_i = NULL_VBO; // Triangles (indices)

	const size_t coordsPerVertex = 2; // We're in 2D
	const size_t stride = 0; // Values in vectors are tightly packed

protected:
	std::vector<glm::vec2> vertices;
	std::vector<Index> indices;

	size_t mode = GL_LINE_LOOP;

public:
	void draw();
};

#endif
