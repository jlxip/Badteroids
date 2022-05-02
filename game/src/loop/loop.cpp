#include <common.hpp>
#include <Badteroids/Badteroids.hpp>
#include "objects.hpp"

extern GLFWwindow* window;
Badteroids game;

bool started = false;

void mainLoop() {
	// Reset everything
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	// - Game starts here -
	if(!started) {
		//ShipModels::Dummy dummy;
		Objects::drawables.alloc(ShipModels::Dummy());
		started = true;
	}

	// Draw everything
	for(auto& x : Objects::drawables)
		x.draw();

	// Shoot frame and manage events
	glfwSwapBuffers(window);
	glfwPollEvents();
}
