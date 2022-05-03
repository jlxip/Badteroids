#ifndef BADTEROIDS_HPP
#define BADTEROIDS_HPP

#include "Ship/Ship.hpp"

// Welcome.
// All objects in Badteroids live in a [-1, +1]x[-1, +1] plane
// The Badteroids class has a 1:1 mapping to the screen
// (-1, -1) is bottom left of the screen; (+1, +1), top right

class Badteroids {
private:
	Ship leftShip = Ship(false);
	//Ship rightShip;

public:
	Badteroids();
	void registerEvents();

	Ship& getLeftShip() { return leftShip; }
	//Ship& getRightShip() { return rightShip; }
};

#endif
