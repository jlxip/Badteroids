#include <common.hpp>
#include <Badteroids/Badteroids.hpp>
#include "objects.hpp"

extern GLFWwindow* window;

// Initialization is postponed, done in <preparations.cpp>
Badteroids* game = nullptr;

// For physics
double lastTick = 0;

// Very temporal variables for demonstration purposes
bool leftPlaying = true;
bool rightPlaying = true;

void mainLoop() {
	// First, take the time
	double t = glfwGetTime();
	double dt = t - lastTick;

	// Reset everything
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	// - Game starts here -

	// Background (a bit different than other objects)
	auto& bgdraw = game->getBackground().getDraw();
	bgdraw.textick(dt);
	bgdraw.draw();

	// Left ship
	if(leftPlaying) {
		Ship& lship = game->getLeftShip();
		lship.getModel().tick(dt);
		if(!lship.checkBounds())
			leftPlaying = false;
		else
			lship.getModel().draw();
	}

	// Right ship
	if(rightPlaying) {
		Ship& rship = game->getRightShip();
		rship.getModel().tick(dt);
		if(!rship.checkBounds())
			rightPlaying = false;
		else
			rship.getModel().draw();
	}

	// Tick and draw inertials drawables, free if they've gone away
	auto iti = Objects::idrawables.begin();
	while(iti != Objects::idrawables.end()) {
		iti->tick(dt);
		iti->draw();
		if(iti->outOfBounds())
			Objects::idrawables.free(iti);
		else
			++iti;
	}

	lastTick = t;

	// Draw regular drawables
	for(auto& x : Objects::drawables)
		x.draw();

	// Shoot frame and manage events
	glfwSwapBuffers(window);
	glfwPollEvents();
}
