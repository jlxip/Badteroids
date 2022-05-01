#include <common.hpp>
#include <GLFW/glfw3.h>
#include <GL/glu.h>

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
}
