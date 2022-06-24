#include "Asteroids.hpp"
#include <Badteroids/RNG/RNG.hpp>
#include "Asteroid/Asteroid.hpp"
#include <loop/objects.hpp>

void Asteroids::tick(Time t) {
	// Must emmit?
	if(t >= lastGap + period) {
		// No, but must schedule for one
		lastGap = t;
		next = t + RNG::genf(rng, 0, period);
	} else if(t >= next) {
		// Yes, emmit it now
		emmit();
		next = t + period; // Make it unreachable
	}
}

void Asteroids::emmit() {
	Asteroid* ast = new Asteroid;

	// How many vertices?
	ast->setVertices(RNG::geni(rng, 3, 7));

	// Size
	float sz = RNG::genf(rng, 0.75, 2.5);
	ast->setSize(sz);

	// Position
	float fsz = ast->getFullSize();
	ast->setx(x + RNG::genf(rng, fsz, 1-fsz));

	// Speed
	ast->setSpeed(speed);

	Objects::cidrawablesp.alloc(dynamic_cast<Drawable*>(ast));
}
