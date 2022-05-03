#include "Badteroids.hpp"

extern GLFWwindow* window;

Badteroids::Badteroids() {
	// Get me a background
	glfwGetFramebufferSize(window, &width, &height);
	background.generate(width, height);
	background.upload();

	// Key presses
	registerEvents();
}
