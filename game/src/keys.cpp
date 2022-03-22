#include <common.hpp>

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	// TODO: pause when ESC
	if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
		return;
	}

	std::cout << key << ' ' << scancode << ' ' << action << ' ' << mods << std::endl;
}
