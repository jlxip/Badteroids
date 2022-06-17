#include "events.hpp"
#include <Badteroids/Badteroids.hpp>

extern Badteroids* game;

void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
	IGNORE(window);

	// Badteroids uses a fixed aspect ratio
	// Set width. Then, set height to closest 16:9
	int h = width * ARY / ARX;
	float starty = ((float)height - h) / 2;
	if(starty < 0)
		starty = 0; // Just in case
	glViewport(0, (height - h) / 2, width, h);

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
