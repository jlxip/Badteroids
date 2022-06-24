#ifndef SHIP_MODEL_HPP
#define SHIP_MODEL_HPP

#include <basics/Drawable/Drawable.hpp>
#include "../Laser/Laser.hpp"

namespace ShipModels {
	class ShipModel : public Drawable {
	public:
		inline bool collisioned(Drawable* other) override {
			if(instanceof<Laser>(other))
				return false;
			return true;
		}
	};
};

#endif
