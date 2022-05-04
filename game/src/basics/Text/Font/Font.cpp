#include "Font.hpp"
#include "bitmap.hpp"

void Font::load(const std::string& path) {
	// First, load the font
	bitmap_image image(path);
	if(!image) {
		std::cerr << "Could not open:" << path << std::endl;
		exit(1);
	}

	width = image.width();
	height = image.height();
	size_t pixels = width * height;
	data.rgba = new glm::vec4[pixels];

	const uint8_t* bgr = image.data();
	// That's BGR, let's turn it into RGBA
	for(size_t i=0; i<pixels; ++i) {
		data.rgba[i] = glm::vec4(
			bgr[i*3+2],
			bgr[i*3+1],
			bgr[i*3+0],
			// Fortunately, it's black and white,
			//   so alpha is any of them
			bgr[i*3]);
	}

	// That's enough of you
	image.clear();

	// Let's create a texture
	texture = Textures::makeTexture(data.raw, width, height, true);
}
