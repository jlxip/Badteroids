#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <common.hpp>

typedef uint32_t TexID;
const TexID NULL_TEXTURE = 0;

namespace Textures {
	TexID makeTexture(const unsigned char* texture, int width, int height);

	inline void useTexture(TexID id) { glBindTexture(GL_TEXTURE_2D, id); }
};

#endif
