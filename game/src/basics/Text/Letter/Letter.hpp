#ifndef LETTER_HPP
#define LETTER_HPP

#include <basics/Drawable/Drawable.hpp>
#include "../Font/Font.hpp"

class Letter : public Drawable {
public:
	Letter() = default;
	Letter(float x, float y, float sz);

	void setVars(float scalex, float scaley, float x, float y);
	inline void setColor(size_t color) {
		switch(color) {
		case 0:
			this->VBO_c = NULL_VBO;
			break;
		case 1:
			this->VBO_c = VBOs::requestGreenVBO(4);
			break;
		case 2:
			this->VBO_c = VBOs::requestRedVBO(4);
			break;
		}
	}
};

#endif
