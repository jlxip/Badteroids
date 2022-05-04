#ifndef BADTEROIDS_HPP
#define BADTEROIDS_HPP

#include "Ship/Ship.hpp"
#include "Background/Background.hpp"

// Welcome.
// All objects in Badteroids live in a [-1, +1]x[-1, +1] plane
// The Badteroids class has a 1:1 mapping to the screen
// (-1, -1) is bottom left of the screen; (+1, +1), top right

class Badteroids {
private:
	int width, height;
	Background background;

	Ship leftShip = Ship(LEFT_SHIP);
	Ship rightShip = Ship(RIGHT_SHIP);

public:
	Badteroids();
	void registerEvents();

	inline Background& getBackground() { return background; }
	Ship& getLeftShip() { return leftShip; }
	Ship& getRightShip() { return rightShip; }
};

#endif
