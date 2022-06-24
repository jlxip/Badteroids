#ifndef BADTEROIDS_HPP
#define BADTEROIDS_HPP

#include "Background/Background.hpp"
#include "Menu/Menu.hpp"
#include "Ship/Ship.hpp"
#include "Asteroids/Asteroids.hpp"
#include "RNG/RNG.hpp"

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
	Asteroids leftAst = Asteroids(-1, RNG::Area::LEFT_ASTEROIDS);
	Asteroids rightAst = Asteroids(0, RNG::Area::RIGHT_ASTEROIDS);

	bool inMenu = true;
	bool playing = false;
	bool showFPS = false;
	bool paused = false;

public:
	Badteroids();
	void init(); // Extra initialization after *game is set

	void registerEvents();
	void startGame();
	void leave();
	void exit();

	inline void tick(Time t) {
		leftAst.tick(t);
		rightAst.tick(t);
	}

	inline Background& getBackground() { return background; }
	inline Ship& getLeftShip() { return leftShip; }
	inline Ship& getRightShip() { return rightShip; }

	inline Asteroids& getLeftAst() { return leftAst; }
	inline Asteroids& getRightAst() { return rightAst; }

	inline bool leftAlive() { return leftShip.alive(); }
	inline bool rightAlive() { return rightShip.alive(); }

	inline Menu& getMenu() { return menu; }

	inline bool isInMenu() const { return inMenu; }
	inline bool isPlaying() const { return playing; }
	inline bool getShowFPS() const { return showFPS; }
	inline void setShowFPS(bool v) { showFPS = v; }

	inline bool isPaused() const { return paused; }
	inline void switchPause() {
		paused = !paused;
		if(paused) {
			menu.changeState(Menu::State::PAUSE);
			inMenu = true;
		} else {
			inMenu = false;
		}
	}
};

#endif
