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

void Letter::setVars(float scale, float x, float y, size_t idx) {
	this->scalex = scale / ARX;
	this->scaley = scale / ARY;
	this->x = x + kerning * idx * this->scalex;
	this->y = y;
}
