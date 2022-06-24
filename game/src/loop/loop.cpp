#include "loop.hpp"
#include <Badteroids/Badteroids.hpp>
#include <Config/Config.hpp>
#include "objects.hpp"
#include <basics/Text/Text.hpp>

extern GLFWwindow* window;

// Initialization is postponed, done in <preparations.cpp>
Badteroids* game = nullptr;
Config globalConfig;

// For physics
Time lastTick = 0;

// FPS measure
size_t framesMeasured = 0;
Time frameAcumTime = 0;
float fps = 0;

void Loop::mainLoop() {
	// First, take the time
	Time t = glfwGetTime();
	Time dt = t - lastTick;
	lastTick = t;

	// Reset everything
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();



	// --- BACKGROUND ---
	game->getBackground().getDraw().draw();
	if(game->isInMenu() && !game->isPaused())
		game->getMenu().draw();
	else if(!game->isInMenu())
		game->getBackground().getDraw().textick(dt);



	// --- DRAWABLES ---
	Loop::manage_idrs(dt);
	Loop::manage_cidrs(dt);

	// Tick more stuff
	if(game->isPlaying() && !game->isPaused())
		game->tick(t);

	// Regular drawables
	for(auto& x : Objects::drawables)
		x.draw();



	// --- PAUSE MENU ---
	if(game->isPaused())
		game->getMenu().draw();



	// --- HUD ---
	// Resources
	if(game->leftAlive())
		game->getLeftShip().drawResources();
	if(game->rightAlive())
		game->getRightShip().drawResources();

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
