#ifndef LOOP_HPP
#define LOOP_HPP

#include <Badteroids/Badteroids.hpp>
#include "objects.hpp"

extern Badteroids* game;

namespace Loop {
	void mainLoop();

	// Inertial drawables
	void manage_idrs(Time dt);

	// Collisionable inertial drawables
	void manage_cidrs(Time dt);
}

#endif
