#include "Drawable.hpp"

void Drawable::tick(float dt) {
	x += inertia.vx * dt;
	y += inertia.vy * dt;
}

void Drawable::draw() const {
	glLoadIdentity();
	glTranslatef(x, y, 0.0);
	glScalef(scalex, scaley, 1.0);

	// Vertices
	glEnableClientState(GL_VERTEX_ARRAY);

	VBOs::useVertices(this->VBO_v);

	if(this->VBO_c) {
		glEnableClientState(GL_COLOR_ARRAY);
		VBOs::useColors(this->VBO_c);
	}

	if(this->VBO_t) {
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glEnable(GL_TEXTURE_2D);
		Textures::useTexture(this->texture);
		VBOs::useTextureCoords(this->VBO_t);
	}

	VBOs::drawElements(this->VBO_i, this->isize, this->mode);

	glDisable(GL_TEXTURE_2D);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}
