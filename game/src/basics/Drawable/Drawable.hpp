#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <common.hpp>
#include <vector>
#include <basics/VBOs/VBOs.hpp>

// Basic drawable object that does NOT change in shape

class Drawable {
protected:
	VBOid VBO_v = NULL_VBO; // Vertices
	VBOid VBO_c = NULL_VBO; // Colors
	VBOid VBO_i = NULL_VBO; // Triangles (indices)

	size_t isize = 0; // How many indices?

	size_t mode = GL_LINE_STRIP;

public:
	inline void draw() const {
		// «Avoid making hundreds of glBindTexture calls per frame, basically»

		// Vertices
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);

		VBOs::useVertices(this->VBO_v);
		VBOs::useColors(this->VBO_c);
		VBOs::drawElements(this->VBO_i, this->isize, this->mode);

		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
	}
};

#endif
