#include "Badteroids.hpp"
#include "Bar/Bar.hpp"
#include "Border/Border.hpp"

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
	playing = true;

	Objects::cidrawablesp.alloc(new Bar);
	Objects::cidrawablesp.alloc(new Border(false, true)); // Left border
	Objects::cidrawablesp.alloc(new Border(false, false)); // Right
	Objects::cidrawablesp.alloc(new Border(true, true)); // Top
	Objects::cidrawablesp.alloc(new Border(true, false)); // Bottom

	// Reset ships
	leftShip.reset();
	rightShip.reset();
}

void Badteroids::leave() {
	inMenu = true;
	paused = playing = false;
	menu.changeState(Menu::State::MAIN);

	Objects::idrawables.clear();

	for(auto x : Objects::cidrawablesp)
		delete x;
	Objects::cidrawablesp.clear();
}

void Badteroids::exit() {
	glfwSetWindowShouldClose(window, true);
}
