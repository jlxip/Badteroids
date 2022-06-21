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
	showLeft = showRight = true;
	Objects::idrawables.alloc(Bar());
}

void Badteroids::exit() {
	glfwSetWindowShouldClose(window, true);
}
