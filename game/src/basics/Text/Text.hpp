#ifndef TEXT_HPP
#define TEXT_HPP

// Gotta draw some text

#include <string>
#include <common.hpp>

class Text {
private:
	std::string str;
	float xorig, yorig; // In case of multiple center() calls
	float scalex, scaley, x, y;

	size_t color = 0;

	static constexpr float kerning = 1;

public:
	struct Fonts {
		static void upload();
	};

	Text() = default;

	Text(const std::string& str, float scale, float x, float y)
		: str(str), xorig(x), yorig(y), x(x), y(y)
	{
		scalex = scale / ARX;
		scaley = scale / ARY;
	}

	inline std::string& getStr() { return str; }
	void xcenter();
	inline void setGreen(bool v) { color = v ? 1 : 0; }
	inline void setRed(bool v) { color = v ? 2 : 0; }
	void draw();
};

#endif
