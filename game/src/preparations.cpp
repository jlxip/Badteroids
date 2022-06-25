#include <Badteroids/Badteroids.hpp>
#include <basics/models/Square/Square.hpp>
#include <basics/Text/Text.hpp>
#include <Badteroids/Ship/models/all.hpp>
#include <Config/Config.hpp>
#include <Badteroids/RNG/RNG.hpp>
#include <Badteroids/Ship/skills/skills.hpp>
#include <ctime>

extern Badteroids* game;
extern Config globalConfig;

// After the window has been created and OpenGL context set,
//   this does further preparations before starting the main loop.
void preparations() {
	// Upload all models to GPU
	BasicModels::Square::upload();
	Text::Fonts::upload();
	ShipModels::Dummy::upload();
	Background::BGDraw::upload();
	Skills::upload();

	// Game initialization
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glEnable(GL_MULTISAMPLE); // AA

	// Alpha channel for text
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	game = new Badteroids;
	game->init(); // *game is set, finish initialization
	globalConfig.load();
	RNG::init(time(NULL));
	glfwSetTime(0); // Here we go, physics
}
