#include "Textures.hpp"

TexID Textures::makeTexture(const unsigned char* texture, int width, int height, bool alpha) {
	TexID ret = NULL_TEXTURE;
	glGenTextures(1, &ret);
	Textures::overwriteTexture(ret, texture, width, height, alpha);
	return ret;
}

void Textures::overwriteTexture(TexID id, const uint8_t* texture, int width, int height, bool alpha) {
	glBindTexture(GL_TEXTURE_2D, id);
	gluBuild2DMipmaps(GL_TEXTURE_2D,
					  alpha ? GL_RGBA : GL_RGB,
					  width,
					  height,
					  alpha ? GL_RGBA : GL_RGB,
					  GL_UNSIGNED_BYTE,
					  texture);
	glBindTexture(GL_TEXTURE_2D, NULL_TEXTURE);
}
