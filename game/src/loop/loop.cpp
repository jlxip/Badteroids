#include <common.hpp>
#include <Badteroids/Badteroids.hpp>
#include "objects.hpp"

extern GLFWwindow* window;

// Initialization is postponed, done in <preparations.cpp>
Badteroids* game = nullptr;

void mainLoop() {
	// Reset everything
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	// - Game starts here -

	// Draw everything
	for(auto& x : Objects::drawables)
		x.draw();

	// Shoot frame and manage events
	glfwSwapBuffers(window);
	glfwPollEvents();
}
