#ifndef SHIP_HPP
#define SHIP_HPP

#include "models/ShipModel.hpp"
#include "Laser/Laser.hpp"
#include <loop/objects.hpp>

// A Ship object lives in one side of the screen
// So, for the left ship, (1, -1) actually corresponds to Badteroids' (0.5, -1)

#define LEFT_SHIP false
#define RIGHT_SHIP true

class Ship {
private:
	Drawable model;
	const float shipScalex = 0.02;
	const float shipScaley = 0.04;

	const float velocityPerPress = 0.1;
	float maxDeviation = velocityPerPress * 0.05; // 5%
	bool iam;

	// Not physically accurate, but playable
	const float shootBlowback = Laser::thevy / 8;

	// Some bounds
	float minx, maxx; // Derived from "iam"
	static constexpr float miny = -1;
	static constexpr float maxy = +1;

public:
	Ship(bool iam_);
	void reset();

	inline Drawable& getModel() { return model; }

	bool checkBounds() const;

	void _move(float dx, float dy);
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void shoot();
};

#endif
