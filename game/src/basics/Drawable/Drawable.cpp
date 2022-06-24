#include "Drawable.hpp"
#include <cmath>

void Drawable::tick(float dt) {
	x += inertia.vx * dt;
	y += inertia.vy * dt;
	r += inertia.w  * dt;
	if(r >= 360)
		r -= 360;
}

void Drawable::draw() const {
	glLoadIdentity();
	glTranslatef(x, y, 0.0);
	glScalef(scalex, scaley, 1.0);
	glRotatef(r, 0, 0, 1.0);

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

bool Drawable::outOfBounds() const {
	if((x - scalex) > (1+OOB_MARGIN))
		return true;
	if((y - scaley) > (1+OOB_MARGIN))
		return true;

	if((x + scalex) < (-1-OOB_MARGIN))
		return true;
	if((y + scaley) < (-1-OOB_MARGIN))
		return true;

	return false;
}
