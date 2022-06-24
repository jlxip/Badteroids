#ifndef ASTEROID_HPP
#define ASTEROID_HPP

#include <basics/Drawable/Drawable.hpp>

class Asteroid : public Drawable {
private:
	size_t n = 0;

public:
	Asteroid();
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