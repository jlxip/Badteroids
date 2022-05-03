#include "RNG.hpp"

static std::mt19937 rngs[RNG::Area::N_AREAS];

void RNG::init(uint32_t seed) {
	for(size_t i=0; i<RNG::Area::N_AREAS; ++i)
		rngs[i].seed(seed++);
}

int RNG::geni(size_t area, int min, int max) {
	std::uniform_int_distribution<> dist(min, max);
	return dist(rngs[area]);
}

float RNG::genf(size_t area, float min, float max) {
	std::uniform_real_distribution<> dist(min, max);
	return dist(rngs[area]);
}
