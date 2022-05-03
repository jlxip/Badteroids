#include <common.hpp>
#include <Badteroids/Badteroids.hpp>
#include "objects.hpp"

extern GLFWwindow* window;

// Initialization is postponed, done in <preparations.cpp>
Badteroids* game = nullptr;

// For physics
double lastTick = 0;

void mainLoop() {
	// Reset everything
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	// - Game starts here -
	double t = glfwGetTime();
	double dt = t - lastTick;

	// Background (a bit different than other objects)
	auto& bgdraw = game->getBackground().getDraw();
	bgdraw.textick(dt);
	bgdraw.draw();

	// Tick and draw inertials drawables
	for(auto& x : Objects::idrawables) {
		x.tick(dt);
		x.draw();
	}

	lastTick = t;

	// Draw everything
	for(auto& x : Objects::drawables)
		x.draw();

	// Shoot frame and manage events
	glfwSwapBuffers(window);
	glfwPollEvents();
}
