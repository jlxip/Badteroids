#include <Badteroids/Badteroids.hpp>

// After the window has been created and OpenGL context set,
//   this does further preparations before starting the main loop.
void preparations() {
	// Upload all models to GPU
	ShipModels::Dummy::upload();

	// Game initialization
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glfwSwapInterval(1); // VSync
}
