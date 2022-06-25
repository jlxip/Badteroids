#include "Asteroids.hpp"
#include <Badteroids/RNG/RNG.hpp>
#include "Asteroid/Asteroid.hpp"
#include <loop/objects.hpp>

void Asteroids::tick() {
	// Must emmit?
	if(now >= lastGap + period) {
		// No, but must schedule for one
		lastGap = now;
		next = now + RNG::genf(rng, 0, period);
	} else if(now >= next) {
		// Yes, emmit it now
		emmit();
		next = now + period; // Make it unreachable
	}

	// What about red asteroid?
	if(now >= lastRedGap + redPeriod) {
		lastRedGap = now;
		nextRed = now + RNG::genf(rng, 0, redPeriod);
	} else if(now >= nextRed) {
		emmit(true);
		nextRed = now + redPeriod;
	}
}

void Asteroids::emmit(bool red) {
	Asteroid* ast = new Asteroid;

	// Type?
	if(red) {
		ast->setType(Asteroid::Type::SKILL);
		ast->setVertices(10); // Easy to recognize
		ast->setSize(3); // Hard to miss
		float fsz = ast->getFullSize();
		ast->setx(x + 0.5-fsz/2); // Veeery hard to miss
	} else {
		float typev = RNG::genf(rng, 0, 1);
		size_t type = Asteroid::Type::REGULAR;
		if(typev < probO)
			type = Asteroid::Type::OXYGEN;
		else if(typev < probH)
			type = Asteroid::Type::HYDROGEN;
		ast->setType(type);

		// How many vertices?
		ast->setVertices(RNG::geni(rng, 3, 7));

		// Size
		float sz = RNG::genf(rng, 0.75, 2.5);
		ast->setSize(sz);

		// Position
		float fsz = ast->getFullSize();
		ast->setx(x + RNG::genf(rng, fsz, 1-fsz));
	}

	// Speed
	ast->setSpeed(speed);

	Objects::cidrawablesp.alloc(dynamic_cast<Drawable*>(ast));
}
