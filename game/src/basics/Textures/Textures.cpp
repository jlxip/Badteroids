#include "Textures.hpp"

TexID Textures::makeTexture(const unsigned char* texture, int width, int height) {
	TexID ret = NULL_TEXTURE;
	glGenTextures(1, &ret);

	glBindTexture(GL_TEXTURE_2D, ret);
	gluBuild2DMipmaps(GL_TEXTURE_2D,
					  GL_RGB,
					  width,
					  height,
					  GL_RGB,
					  GL_UNSIGNED_BYTE,
					  texture);
	glBindTexture(GL_TEXTURE_2D, NULL_TEXTURE);

	return ret;
}
