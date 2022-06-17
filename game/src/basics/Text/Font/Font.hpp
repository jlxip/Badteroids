#ifndef FONT_HPP
#define FONT_HPP

#include <basics/Textures/Textures.hpp>

class Font {
private:
	uint8_t* data;

	size_t width = 0;
	size_t height = 0;

	TexID texture = NULL_TEXTURE;

public:
	void load(const std::string& path);

	inline TexID getTexture() const { return texture; }
	inline size_t getWidth() const { return width; }
	inline size_t getHeight() const { return height; }
};

#endif
