#ifndef SHIP_MODEL_HPP
#define SHIP_MODEL_HPP

#include <basics/Drawable/Drawable.hpp>
#include "../Laser/Laser.hpp"
#include "../Ship.hpp"
#include <Badteroids/Asteroids/Drop/Drop.hpp>

namespace ShipModels {
	class ShipModel : public Drawable {
	private:
		Ship* parent;

	public:
		inline void setParent(Ship* x) { parent = x; }
		inline Ship& getParent() { return *parent; }

		inline bool collisioned(Drawable* other) override {
			if(instanceof<Laser>(other))
				return false;
			if(instanceof<Drop>(other))
				return false;
			return true;
		}
	};
};

#endif
