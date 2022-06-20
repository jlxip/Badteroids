#ifndef LETTER_HPP
#define LETTER_HPP

#include <basics/Drawable/Drawable.hpp>
#include "../Font/Font.hpp"

class Letter : public Drawable {
public:
	Letter() = default;
	Letter(float x, float y, float sz);

	void setVars(float scalex, float scaley, float x, float y);
	inline void setGreen(bool v) {
		if(v)
			this->VBO_c = VBOs::requestGreenVBO(4);
		else
			this->VBO_c = NULL_VBO;
	}
};

#endif
