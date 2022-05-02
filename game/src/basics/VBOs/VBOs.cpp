#include "VBOs.hpp"

static VBOid makeVBO(GLuint type, GLuint sz, const GLvoid* ptr) {
	VBOid ret;
	glGenBuffers(1, &ret); // Creation
	glBindBuffer(type, ret); // Activation
	glBufferData(type, sz, ptr, GL_STATIC_DRAW); // Transfer RAM -> GPU
	glBindBuffer(type, NULL_VBO); // Deactivation
	return ret;
}

// --- BOOT TIME ---
// These are only called when starting the game
VBOid VBOs::makeVertices(const glm::vec2* vertices, size_t n) {
	return makeVBO(GL_ARRAY_BUFFER, n * sizeof(glm::vec2), vertices);
}

VBOid VBOs::makeIndices(const Index* indices, size_t n) {
	return makeVBO(GL_ELEMENT_ARRAY_BUFFER, n * sizeof(Index), indices);
}

// --- RUN TIME ---
// These are called multiple times per frame
static const size_t coordsPerVertex = 2; // We're in 2D
static const size_t stride = 0; // Values in vectors are tightly packed
#define VBO_NULL_OFFSET 0

void VBOs::useVertices(VBOid id) {
	// Assuming GL_VERTEX_ARRAY is enabled
	glBindBuffer(GL_ARRAY_BUFFER, id); // Mount
	glVertexPointer(coordsPerVertex,
					GL_FLOAT,
					stride,
					VBO_NULL_OFFSET);
	glBindBuffer(GL_ARRAY_BUFFER, NULL_VBO); // Unmount
}

void VBOs::drawElements(VBOid id, size_t isize, GLenum mode) {
	// Assuming GL_VERTEX_ARRAY is enabled
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id); // Mount
	glDrawElements(mode,
				   isize,
				   GL_UNSIGNED_INT,
				   VBO_NULL_OFFSET);
	glBindBuffer(GL_ARRAY_BUFFER, NULL_VBO); // Unmount
}