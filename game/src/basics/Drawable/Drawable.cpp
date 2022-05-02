#include "Drawable.hpp"

void Drawable::draw() const {
	// «Avoid making hundreds of glBindTexture calls per frame, basically»

	// Restore ModelView matrix
	glPushMatrix(); {
		glLoadIdentity();
		glScalef(scalex, scaley, 1.0);
		glTranslatef(movex, movey, 0.0);

		// Vertices
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);

		VBOs::useVertices(this->VBO_v);
		VBOs::useColors(this->VBO_c);
		VBOs::drawElements(this->VBO_i, this->isize, this->mode);

		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);

	} glPopMatrix();
}
