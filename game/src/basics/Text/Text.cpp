#include "Text.hpp"
#include "Font/Font.hpp"
#include <unordered_map>
#include "Letter/Letter.hpp"

// Font
Font font;
static const char pathMMD[] = "assets/fonts/MajorMonoDisplay.bmp";
static const size_t symbolsPerRow = 16;
static const float fontSize = 64;

// Letters
std::unordered_map<char, Letter> letters;

static inline glm::vec2 pos2coords(size_t pos) {
	glm::vec2 ret = {
		pos % symbolsPerRow,
		pos / symbolsPerRow
	};

	ret.x *= fontSize; ret.y *= fontSize;
	ret.x /= font.getWidth(); ret.y /= font.getHeight();
	return ret;
}

void Text::Fonts::upload() {
	font.load(pathMMD);
	float delta = fontSize / font.getWidth();

	for(char i=' '; i<='~'; ++i) {
		auto coords = pos2coords(i - ' ');
		letters[i] = {coords.x, coords.y, delta};
	}

	// Dirty hack
	auto aux = pos2coords(139);
	letters['{'] = {aux.x, aux.y, delta};
	aux = pos2coords(155);
	letters['}'] = {aux.x, aux.y, delta};
}

void Text::xcenter() {
	float endx = kerning * (str.size()-1) * scalex;
	float xwide = endx;
	x = -xwide/2;
}

void Text::draw() {
	for(size_t i=0; i<str.size(); ++i) {
		char c = str[i];

		if(letters.find(c) == letters.end()) {
			std::cout << "Unmapped character: " << c << std::endl;
			exit(1001);
		}

		letters[c].setVars(scalex, scaley, x + kerning*i*scalex, y);
		letters[c].setColor(color);
		letters[c].draw();
	}
}
