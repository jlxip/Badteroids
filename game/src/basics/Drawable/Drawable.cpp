#include "Drawable.hpp"

void Drawable::tick(float dt) {
	x += inertia.vx * dt;
	y += inertia.vy * dt;
}

void Drawable::draw() const {
	// «Avoid making hundreds of glBindTexture calls per frame, basically»

	glLoadIdentity();
	glTranslatef(x, y, 0.0);
	glScalef(scalex, scaley, 1.0);

	// Vertices
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	VBOs::useVertices(this->VBO_v);
	VBOs::useColors(this->VBO_c);
	VBOs::drawElements(this->VBO_i, this->isize, this->mode);

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}
