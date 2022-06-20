#include "Letter.hpp"
#include <basics/models/Square/Square.hpp>

extern Font font;

#include <iostream>
Letter::Letter(float x, float y, float sz) {
	this->VBO_v = BasicModels::Square::VBO_v;
	this->texture = font.getTexture();

	glm::vec2* texcoords = new glm::vec2[4];
	texcoords[0] = {x, y};
	texcoords[1] = {x+sz, y};
	texcoords[2] = {x+sz, y+sz};
	texcoords[3] = {x, y+sz};

	this->VBO_t = VBOs::makeTextureCoords(texcoords, BasicModels::Square::vsize);
	this->VBO_i = BasicModels::Square::VBO_i;
	this->isize = BasicModels::Square::isize;
	this->mode = BasicModels::Square::mode;
}

void Letter::setVars(float scalex, float scaley, float x, float y) {
	this->scalex = scalex;
	this->scaley = scaley;
	this->x = x;
	this->y = y;
}
