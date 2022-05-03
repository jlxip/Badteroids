#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <common.hpp>

typedef uint32_t TexID;
const TexID NULL_TEXTURE = 0;

namespace Textures {
	TexID makeTexture(const uint8_t* texture, int width, int height);
	void overwriteTexture(TexID id, const uint8_t* texture, int width, int height);

	inline void useTexture(TexID id) { glBindTexture(GL_TEXTURE_2D, id); }
};

#endif
