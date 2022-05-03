#include "events.hpp"
#include <Badteroids/Badteroids.hpp>

extern Badteroids* game;

void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
	IGNORE(window);

	// Whole screen is viewport
	glViewport(0, 0, width, height);

	// Set up orthographic projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// Origin at the center
	gluOrtho2D(-1, 1, -1, 1);
	// Go back
	glMatrixMode(GL_MODELVIEW);

	// New background
	if(game) {
		game->getBackground().generate(width, height);
		game->getBackground().upload();
	}
}
