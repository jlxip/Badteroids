#ifndef VBOS_HPP
#define VBOS_HPP

#include <common.hpp>
typedef uint32_t Index;

// This namespace defines everything related to Vertex Buffer Objects
// One type of drawable has a few of these (2 or 3)
// All drawables of the same type have the same VBOs, or very similar

typedef uint32_t VBOid;
const VBOid NULL_VBO = 0;

namespace VBOs {
	// --- BOOT TIME ---
	VBOid makeVertices(const glm::vec2* vertices, size_t n);
	VBOid makeIndices(const Index* indices, size_t n);
	VBOid makeColors(const glm::vec3* colors, size_t n);
	inline VBOid makeTextureCoords(const glm::vec2* texc, size_t n) {
		return makeVertices(texc, n);
	}

	// --- RUN TIME ---
	void useVertices(VBOid id);
	void useColors(VBOid id);
	void useTextureCoords(VBOid id);
	void drawElements(VBOid id, size_t isize, GLenum mode);

	// --- AXILIARY ---
	VBOid requestGreenVBO(size_t vertices);
};

#endif
