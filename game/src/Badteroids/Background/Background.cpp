#include "Background.hpp"
#include <Badteroids/RNG/RNG.hpp>
#include <cmath>
#include <cstring>

// Many thanks: https://wwwtyro.net/2016/10/22/2D-space-scene-procgen.html

void Background::generate(size_t width_, size_t height_) {
	if(this->texture)
		delete [] (this->texture);

	this->width = width_;
	this->height = height_;

	size_t pixels = width_ * height_;
	this->texture = new uint8_t[pixels*3];

	// Fill the texture with black
	memset(this->texture, 0, pixels*3);

	size_t count = pixels * density;

	while(count--) {
		size_t idx = RNG::geni(RNG::Area::BACKGROUND, 0, pixels-1);

		// Get brightness from exponential distribution
		float random = RNG::genf(RNG::Area::BACKGROUND, 0, 1);
		// color=0 is black (log(1)=0)
		// color=0.9999... is white
		random = 1 - random;
		if(random)
			random = log(random);
		size_t color = random * 255 * -brightness;

		// Minor protection
		if(color > 255) color = 255;

		this->texture[idx*3+0] = color;
		this->texture[idx*3+1] = color;
		this->texture[idx*3+2] = color;
	}
}

void Background::upload() {
	if(!tex) {
		tex = Textures::makeTexture(texture, width, height);
		drawable.setTexID(tex);
	} else {
		Textures::overwriteTexture(tex, texture, width, height);
	}
}
