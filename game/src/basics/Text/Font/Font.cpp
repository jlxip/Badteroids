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
	data = new uint8_t[pixels*4];

	uint8_t* bgr = image.data();
	// That's BGR, let's turn it into RGBA
	for(size_t i=0; i<pixels; ++i) {
		data[i*4+0] = bgr[i*3+2]; // R
		data[i*4+1] = bgr[i*3+1]; // G
		data[i*4+2] = bgr[i*3+0]; // B
		data[i*4+3] = bgr[i*3+0]; // A, any channel (it's b&w)
	}

	// That's enough of you
	image.clear();

	// Let's create a texture
	texture = Textures::makeTexture(data, width, height, true);
}
