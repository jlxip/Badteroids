#ifndef FONT_HPP
#define FONT_HPP

#include <basics/Textures/Textures.hpp>

class Font {
private:
	union {
		glm::vec4* rgba;
		uint8_t* raw;
	} data;

	size_t width = 0;
	size_t height = 0;

	TexID texture = NULL_TEXTURE;

public:
	void load(const std::string& path);

	inline TexID getTexture() const { return texture; }
};

#endif
