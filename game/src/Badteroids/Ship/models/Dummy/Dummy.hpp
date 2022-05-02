#ifndef DUMMY_SHIP_HP
#define DUMMY_SHIP_HPP

#include <basics/Drawable/Drawable.hpp>

namespace ShipModels {
	class Dummy : public Drawable {
	public:
		static void upload();
		Dummy();
	};
};

#endif
