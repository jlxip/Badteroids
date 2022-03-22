#include <common.hpp>
#include <Badteroids/Badteroids.hpp>

extern GLFWwindow* window;
Badteroids game;

void mainLoop() {
	// game would be here lmao

	glfwSwapBuffers(window);
	glfwPollEvents();
}
