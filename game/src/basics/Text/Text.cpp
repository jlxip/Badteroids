#include "Text.hpp"
#include "Font/Font.hpp"
#include <unordered_map>
#include "Letter/Letter.hpp"

// Font
Font font;
static const char pathHack[] = "assets/fonts/Hack.bmp";
static const size_t symbolsPerRow = 16;
static const size_t beginNumbers = 1*symbolsPerRow;
static const size_t beginUppercase = 2*symbolsPerRow + 1;
static const size_t beginLowercase = 4*symbolsPerRow + 1;
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

	// Uppercase
	for(char i='A'; i<='Z'; ++i) {
		auto coords = pos2coords(beginUppercase + i - 'A');
		letters[i] = {coords.x, coords.y, delta};
	}

	// Lowercase
	for(char i='a'; i<='z'; ++i) {
		auto coords = pos2coords(beginLowercase + i - 'a');
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
