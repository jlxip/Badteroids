#include "Badteroids.hpp"
#include "Bar/Bar.hpp"

extern GLFWwindow* window;

Badteroids::Badteroids() {
	// Get me a background
	glfwGetFramebufferSize(window, &width, &height);
	background.generate(width, height);
	background.upload();

	// Key presses
	registerEvents();
}

void Badteroids::init() {
	// Initialize menu
	menu.init();
}

void Badteroids::startGame() {
	inMenu = false;
	playing = showLeft = showRight = true;
	Objects::idrawables.alloc(Bar());

	// Reset ships
	leftShip.reset();
	rightShip.reset();
}

void Badteroids::leave() {
	inMenu = true;
	paused = false;
	menu.changeState(Menu::State::MAIN);
	playing = showLeft = showRight = false;
	Objects::idrawables.clear();
}

void Badteroids::exit() {
	glfwSetWindowShouldClose(window, true);
}
