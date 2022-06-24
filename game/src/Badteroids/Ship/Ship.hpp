#ifndef SHIP_HPP
#define SHIP_HPP

#include "Laser/Laser.hpp"
#include <loop/objects.hpp>

// A Ship object lives in one side of the screen
// So, for the left ship, (1, -1) actually corresponds to Badteroids' (0.5, -1)

#define LEFT_SHIP false
#define RIGHT_SHIP true

class Ship {
private:
	ObjID obj = 0;
	const float shipScalex = 0.01;
	const float shipScaley = 0.02;

	const float velocityPerPress = 0.1;
	float maxDeviation = velocityPerPress * 0.05; // 5%
	bool iam;

	// Some bounds
	float minx, maxx; // Derived from "iam"
	static constexpr float miny = -1;
	static constexpr float maxy = +1;

	// Resources
	struct {
		float h = 100;
		float o = 100;
	} resources;
	static constexpr float HYDROGEN_BURN = 2;
	static constexpr float OXYGEN_PER_HYDROGEN = 1./4;
	static constexpr float H_PER_DROP = 50;
	static constexpr float O_PER_DROP = 50;

public:
	Ship(bool iam_);
	void init();
	void reset();
	inline bool alive() {
		if(!obj)
			return false;
		if(Objects::cidrawablesp.freed(obj))
			return (obj = 0);
		return true;
	}

	inline Drawable& getModel() { return *Objects::cidrawablesp[obj]; }
	void drawResources();

	inline void addH() {
		resources.h += H_PER_DROP;
		if(resources.h > 100)
			resources.h = 100;
	}

	inline void addO() {
		resources.o += O_PER_DROP;
		if(resources.o > 100)
			resources.o = 100;
	}

	void _move(float dx, float dy);
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void shoot();
};

#endif
