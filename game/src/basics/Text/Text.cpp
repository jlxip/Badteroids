#include "Text.hpp"
#include "Font/Font.hpp"
#include <unordered_map>
#include "Letter/Letter.hpp"

// Font
Font font;
static const char pathHack[] = "assets/fonts/Hack.bmp";
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
	font.load(pathHack);
	float delta = fontSize / font.getWidth();

	for(char i=' '; i<='~'; ++i) {
		auto coords = pos2coords(i - ' ');
		letters[i] = {coords.x, coords.y, delta};
	}
}

void Text::draw() {
	for(size_t i=0; i<str.size(); ++i) {
		char c = str[i];

		if(letters.find(c) == letters.end()) {
			std::cout << "Unmapped character: " << c << std::endl;
			exit(1001);
		}

		letters[c].setVars(scale, x, y, i);
		letters[c].draw();
	}
}
