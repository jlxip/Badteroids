#include <common.hpp>
#include <Badteroids/Badteroids.hpp>

extern GLFWwindow* window;
Badteroids game;

#include <basics/shapes/Triangle/Triangle.hpp>
static Triangle test(glm::vec2(0.0, 0.5), glm::vec2(-0.5, -0.5), glm::vec2(0.5, -0.5));

void mainLoop() {
	// Reset everything
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	// Game start here
	test.draw();

	// Shoot frame and manage events
	glfwSwapBuffers(window);
	glfwPollEvents();
}
