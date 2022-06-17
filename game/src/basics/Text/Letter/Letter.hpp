#ifndef LETTER_HPP
#define LETTER_HPP

#include <basics/Drawable/Drawable.hpp>
#include "../Font/Font.hpp"

class Letter : public Drawable {
private:
	static constexpr float kerning = 1;

public:
	Letter() = default;
	Letter(float x, float y, float sz);

	void setVars(float scale, float x, float y, size_t idx);
};

#endif
