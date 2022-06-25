#ifndef ASTEROID_HPP
#define ASTEROID_HPP

#include <basics/Drawable/Drawable.hpp>

class Asteroid : public Drawable {
public:
	struct Type {
		enum {
			REGULAR,
			HYDROGEN,
			OXYGEN,
			SKILL,
		};
	};

private:
	size_t n = 0;
	size_t type = Type::REGULAR;

public:
	inline Asteroid() {
		this->mode = GL_LINES;
	}

	inline void setType(size_t type_) { type = type_; }

	void setVertices(size_t n);

	inline void setSize(float sz) {
		// Aspect ratio
		this->scalex = sz / ARX;
		this->scaley = sz / ARY;

		this->y = 1 + scaley; // Above the screen

		this->inertia.w = 500/sz;
	}

	inline float getFullSize() { return scalex; }

	inline void setx(float x_) { this->x = x_; }
	inline void setSpeed(float speed) {
		this->inertia.vy = -speed / (15 * scalex);
	}

	bool collisioned(Drawable* other) override;
};

#endif
