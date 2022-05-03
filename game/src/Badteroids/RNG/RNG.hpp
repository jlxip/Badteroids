#ifndef RNG_HPP
#define RNG_HPP

#include <random>
#include <vector>

namespace RNG {
	struct Area {
		enum {
			LEFT_SHIP_DEVIATION,
			RIGHT_SHIP_DEVIATION,
			N_AREAS
		};
	};

	void init(uint32_t seed);

	int geni(size_t area, int min, int max);
	float genf(size_t area, float min, float max);
};

#endif
