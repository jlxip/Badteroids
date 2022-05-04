#include <Badteroids/Badteroids.hpp>
#include <basics/models/Square/Square.hpp>
#include <basics/Text/Text.hpp>
#include <Badteroids/Bar/Bar.hpp>

extern Badteroids* game;

// After the window has been created and OpenGL context set,
//   this does further preparations before starting the main loop.
void preparations() {
	// Upload all models to GPU
	Text::Fonts::upload();
	BasicModels::Square::upload();
	ShipModels::Dummy::upload();
	Background::BGDraw::upload();
	Laser::upload();
	Bar::upload();

	// Game initialization
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glEnable(GL_MULTISAMPLE); // AA
	glfwSwapInterval(1); // VSync

	game = new Badteroids;
	glfwSetTime(0); // Here we go, physics
}
