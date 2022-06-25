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
Time now;
static Time lastTick = 0;

// FPS measure
static size_t framesMeasured = 0;
static Time frameAcumTime = 0;
static float fps = 0;

void Loop::mainLoop() {
	// First, take the time
	now = glfwGetTime();
	Time dt = now - lastTick;
	lastTick = now;

	// Reset everything
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();



	// --- BACKGROUND ---
	game->getBackground().getDraw().draw();
	if(game->isInMenu() && !game->isPaused())
		game->getMenu().draw();
	else if(!game->isInMenu())
		game->getBackground().getDraw().textick(dt);
	game->veryFirstTick(dt);


	// --- DRAWABLES ---
	Loop::manage_idrs(dt);
	Loop::manage_cidrs(dt);

	// Tick more stuff
	if(game->isPlaying() && !game->isPaused())
		game->tick(dt);

	// Regular drawables
	for(auto& x : Objects::drawables)
		x.draw();

	game->veryLastTick();



	// --- PAUSE MENU ---
	if(game->isPaused())
		game->getMenu().draw();



	// --- HUD ---
	if(game->isPlaying())
		game->drawHUD();

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
