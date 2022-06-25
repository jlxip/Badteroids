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
	Time lastGap = -10000;
	// And when in the current gap it must be emitted
	Time next = -10000;

	// Equivalent to above, but with the red asteroid
	static constexpr Time redPeriod = GAME_DURATION / N_SKILLS;
	Time lastRedGap = -10000;
	Time nextRed = -10000;

	float probH = 0.2;
	float probO = 0.1;

	static constexpr float minSize = 0.75;
	float maxSize = 2.5;

	bool disabled = false;

	void emmit(bool red=false);

public:
	Asteroids(float x, size_t rng)
		: x(x), rng(rng)
	{}

	void tick();
	inline void reset() {
		lastGap = next = lastRedGap = nextRed = -10000; // Big enough.
		maxSize = 2.5;
		disabled = false;
	}

	inline void setAsteroidBelt(bool v) {
		if(v) {
			// Turn on
			period = 0.5;
			maxSize = 0.75;
		} else {
			// Normal values
			period = 2;
			maxSize = 2.5;
		}
	}

	inline void disable() { disabled = true; }
};

#endif
