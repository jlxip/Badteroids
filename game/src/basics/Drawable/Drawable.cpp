#include "Drawable.hpp"
#include <common.hpp>

VBOid makeVBO(GLuint type, GLuint sz, GLvoid* ptr) {
	VBOid ret;
	glGenBuffers(1, &ret); // Creation
	glBindBuffer(type, ret); // Activation
	glBufferData(type, sz, ptr, GL_STATIC_DRAW); // Transfer RAM -> GPU
	glBindBuffer(type, NULL_VBO); // Deactivation
	return ret;
}

void Drawable::draw() {
	// «Avoid making hundreds of glBindTexture calls per frame, basically»

	if(!this->VBO_v) {
		// No VBO ids allocated

		// Vertices
		this->VBO_v = makeVBO(GL_ARRAY_BUFFER,
							  this->vertices.size() * sizeof(glm::vec2),
							  this->vertices.data());
		// Indices
		this->VBO_i = makeVBO(GL_ELEMENT_ARRAY_BUFFER,
							  this->indices.size() * sizeof(Index),
							  this->indices.data());

	}

	// Vertices
	glEnableClientState(GL_VERTEX_ARRAY);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO_v);
	glVertexPointer(this->coordsPerVertex,
					GL_FLOAT,
					this->stride,
					VBO_NULL_OFFSET);
	glBindBuffer(GL_ARRAY_BUFFER, NULL_VBO);

	// Indices
	//glEnableClientState(GL_VERTEX_ARRAY);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->VBO_i);
	glDrawElements(this->mode,
				   this->indices.size() * sizeof(Index),
				   GL_UNSIGNED_INT,
				   VBO_NULL_OFFSET);
	glBindBuffer(GL_ARRAY_BUFFER, NULL_VBO);

	glDisableClientState(GL_VERTEX_ARRAY);
}
