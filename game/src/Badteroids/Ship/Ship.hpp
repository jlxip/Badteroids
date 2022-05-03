#ifndef SHIP_HPP
#define SHIP_HPP

#include "models/ShipModel.hpp"
#include <loop/objects.hpp>

// A Ship object lives in one side of the screen
// So, for the left ship, (1, -1) actually corresponds to Badteroids' (0.5, -1)

#define LEFT_SHIP false
#define RIGHT_SHIP true

class Ship {
private:
	ObjID model;
	const float shipScalex = 0.02;
	const float shipScaley = 0.04;

	const float velocityPerPress = 0.1;
	float maxDeviation = velocityPerPress * 0.05; // 5%
	bool iam;

public:
	Ship(bool iam_);

	inline ObjID getModel() const { return model; }

	void _move(float dx, float dy);
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
};

#endif
