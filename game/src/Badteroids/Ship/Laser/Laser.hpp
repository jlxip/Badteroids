#ifndef LASER_HPP
#define LASER_HPP

// Visible part of a shoot

#include <basics/Drawable/Drawable.hpp>

class Laser : public Drawable {
public:
	// These look very nice in the forced aspect ratio
	static constexpr float sx = 0.003;
	static constexpr float sy = 0.025;

	// Units per second
	static constexpr float thevx = 0;
	static constexpr float thevy = 2;

	Laser(float x, float y);
};

#endif
