#ifndef BADTEROIDS_HPP
#define BADTEROIDS_HPP

#include "Background/Background.hpp"
#include "Menu/Menu.hpp"
#include "Ship/Ship.hpp"

// Welcome.
// All objects in Badteroids live in a [-1, +1]x[-1, +1] plane
// The Badteroids class has a 1:1 mapping to the screen
// (-1, -1) is bottom left of the screen; (+1, +1), top right

class Badteroids {
private:
	int width, height;
	Background background;

	Menu menu;

	Ship leftShip = Ship(LEFT_SHIP);
	Ship rightShip = Ship(RIGHT_SHIP);

	bool showLeft = false;
	bool showRight = false;

	bool inMenu = true;
	bool showFPS = false;

public:
	Badteroids();
	void registerEvents();
	void startGame();

	inline Background& getBackground() { return background; }
	inline Ship& getLeftShip() { return leftShip; }
	inline Ship& getRightShip() { return rightShip; }

	inline bool getShowLeft() const { return showLeft; }
	inline void setShowLeft(bool v) { showLeft = v;}
	inline bool getShowRight() const { return showRight; }
	inline void setShowRight(bool v) { showRight = v; }

	inline Menu& getMenu() { return menu; }

	inline bool isInMenu() const { return inMenu; }
	inline bool getShowFPS() const { return showFPS; }
	inline void switchShowFPS() { showFPS = !showFPS; }
};

#endif
