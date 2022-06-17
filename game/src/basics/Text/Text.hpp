#ifndef TEXT_HPP
#define TEXT_HPP

// Gotta draw some text

#include <string>

class Text {
private:
	std::string str;
	float scale, x, y;

public:
	struct Fonts {
		static void upload();
	};

	Text(const std::string& str, float scale, float x, float y)
		: str(str), scale(scale), x(x), y(y)
	{}

	void draw();
};

#endif
