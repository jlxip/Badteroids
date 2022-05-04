#include "Badteroids.hpp"
#include "Bar/Bar.hpp"

extern GLFWwindow* window;

Badteroids::Badteroids() {
	// Get me a background
	glfwGetFramebufferSize(window, &width, &height);
	background.generate(width, height);
	background.upload();

	// Object creation
	Objects::idrawables.alloc(Bar());

	// Key presses
	registerEvents();
}
