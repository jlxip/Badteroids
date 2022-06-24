#ifndef ASTEROIDS_HPP
#define ASTEROIDS_HPP

#include <common.hpp>

class Asteroids {
private:
	float x = 0;
	size_t rng = 0;
	float speed = 1;

	// How much time (in seconds) to wait between asteroids
	Time period = 2;
	inline double freq() { return 1./period; }

	// When was the last time gap
	Time lastGap = 0;
	// And when in the current gap it must be emitted
	Time next = 0;

public:
	Asteroids(float x, size_t rng)
		: x(x), rng(rng)
	{}

	void tick(Time t);
	void emmit();
};

#endif
