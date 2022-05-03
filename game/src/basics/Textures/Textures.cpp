#include "Textures.hpp"

TexID Textures::makeTexture(const unsigned char* texture, int width, int height) {
	TexID ret = NULL_TEXTURE;
	glGenTextures(1, &ret);
	Textures::overwriteTexture(ret, texture, width, height);
	return ret;
}

void Textures::overwriteTexture(TexID id, const uint8_t* texture, int width, int height) {
	glBindTexture(GL_TEXTURE_2D, id);
	gluBuild2DMipmaps(GL_TEXTURE_2D,
					  GL_RGB,
					  width,
					  height,
					  GL_RGB,
					  GL_UNSIGNED_BYTE,
					  texture);
	glBindTexture(GL_TEXTURE_2D, NULL_TEXTURE);
}
