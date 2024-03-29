#include "VBOs.hpp"

static VBOid makeVBO(GLuint type, GLuint sz, const GLvoid* ptr, bool dynamic) {
	VBOid ret;
	glGenBuffers(1, &ret); // Creation
	VBOs::overwriteVBO(ret, type, sz, ptr, dynamic);
	return ret;
}

void VBOs::overwriteVBO(VBOid id, GLuint type, GLuint sz, const GLvoid* ptr, bool dynamic) {
	glBindBuffer(type, id); // Attach
	GLenum flag = dynamic ? GL_STREAM_DRAW : GL_STATIC_DRAW;
	glBufferData(type, sz, ptr, flag); // Transfer RAM -> GPU
	glBindBuffer(type, NULL_VBO); // Deattach
}

// --- BOOT TIME ---
// These are only called when starting the game
VBOid VBOs::makeVertices(const glm::vec2* vertices, size_t n, bool dynamic) {
	return makeVBO(GL_ARRAY_BUFFER, n * sizeof(glm::vec2), vertices, dynamic);
}

VBOid VBOs::makeColors(const glm::vec3* colors, size_t n, bool dynamic) {
	return makeVBO(GL_ARRAY_BUFFER, n * sizeof(glm::vec3), colors, dynamic);
}

VBOid VBOs::makeIndices(const Index* indices, size_t n, bool dynamic) {
	return makeVBO(GL_ELEMENT_ARRAY_BUFFER, n * sizeof(Index), indices, dynamic);
}

// --- RUN TIME ---
// These are called multiple times per frame
static const size_t coordsPerVertex = 2; // We're in 2D
static const size_t colorsPerVertex = 3; // RGB
static const size_t stride = 0; // Values in vectors are tightly packed
#define VBO_NULL_OFFSET 0

void VBOs::useVertices(VBOid id) {
	// Assuming GL_VERTEX_ARRAY is enabled
	glBindBuffer(GL_ARRAY_BUFFER, id); // Attach
	glVertexPointer(coordsPerVertex,
					GL_FLOAT,
					stride,
					VBO_NULL_OFFSET);
	glBindBuffer(GL_ARRAY_BUFFER, NULL_VBO); // Deattach
}

void VBOs::useColors(VBOid id) {
	// Assuming GL_COLOR_ARRAY is enabled
	glBindBuffer(GL_ARRAY_BUFFER, id); // Attach
	glColorPointer(colorsPerVertex,
				   GL_FLOAT,
				   stride,
				   VBO_NULL_OFFSET);
	glBindBuffer(GL_ARRAY_BUFFER, NULL_VBO); // Deattach
}

void VBOs::useTextureCoords(VBOid id) {
	// Assuming GL_TEXTURE_COORD_ARRAY is enabled
	glBindBuffer(GL_ARRAY_BUFFER, id); // Attach
	glTexCoordPointer(coordsPerVertex,
					  GL_FLOAT,
					  stride,
					  VBO_NULL_OFFSET);
	glBindBuffer(GL_ARRAY_BUFFER, NULL_VBO); // Deattach
}

void VBOs::drawElements(VBOid id, size_t isize, GLenum mode) {
	// Assuming GL_VERTEX_ARRAY is enabled
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id); // Attach
	glDrawElements(mode,
				   isize,
				   GL_UNSIGNED_INT,
				   VBO_NULL_OFFSET);
	glBindBuffer(GL_ARRAY_BUFFER, NULL_VBO); // Deattach
}
