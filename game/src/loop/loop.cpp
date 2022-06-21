#include <common.hpp>
#include <Badteroids/Badteroids.hpp>
#include <Config/Config.hpp>
#include "objects.hpp"
#include <basics/Text/Text.hpp>

extern GLFWwindow* window;

// Initialization is postponed, done in <preparations.cpp>
Badteroids* game = nullptr;
Config globalConfig;

// For physics
double lastTick = 0;

// FPS measure
size_t framesMeasured = 0;
double frameAcumTime = 0;
float fps = 0;

void mainLoop() {
	// First, take the time
	double t = glfwGetTime();
	double dt = t - lastTick;

	// Reset everything
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	// - Game starts here -

	// Background (a bit different than other objects)
	game->getBackground().getDraw().draw();
	if(game->isInMenu() && !game->isPaused())
		game->getMenu().draw();
	else if(!game->isInMenu())
		game->getBackground().getDraw().textick(dt);

	// Left ship
	if(game->getShowLeft()) {
		Ship& lship = game->getLeftShip();
		if(!game->isPaused())
			lship.getModel().tick(dt);
		if(!lship.checkBounds())
			game->setShowLeft(false); // Temporal way of dying
		else
			lship.getModel().draw();
	}

	// Right ship
	if(game->getShowRight()) {
		Ship& rship = game->getRightShip();
		if(!game->isPaused())
			rship.getModel().tick(dt);
		if(!rship.checkBounds())
			game->setShowRight(false);
		else
			rship.getModel().draw();
	}

	// Tick and draw inertials drawables, free if they've gone away
	auto iti = Objects::idrawables.begin();
	while(iti != Objects::idrawables.end()) {
		if(!game->isPaused())
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

	// Pause menu, draw above all
	if(game->isPaused())
		game->getMenu().draw();

	// FPS
	frameAcumTime += dt;
	++framesMeasured;
	if(frameAcumTime >= 1) {
		// One second has passed, get the measure
		fps = framesMeasured;
		frameAcumTime = framesMeasured = 0;
	}

	if(game->getShowFPS()) {
		std::string fpsstr = "fps: " + std::to_string((size_t)fps);
		Text(fpsstr, 0.5, -0.9, 0.9).draw();
	}

	// Shoot frame and manage events
	glfwSwapBuffers(window);
	glfwPollEvents();
}
