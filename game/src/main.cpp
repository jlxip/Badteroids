#include <common.hpp>

void errorCallback(int error, const char* description) {
	std::cerr << "Error " << error << std::endl;
	std::cerr << description << std::endl;
	exit(error);
}

void keyCallback(GLFWwindow*, int, int, int, int);
void mainLoop();

GLFWwindow* window;

int main() {
	if(!glfwInit()) {
		std::cerr << "Could not initialize GLFW" << std::endl;
		return 1;
	}

	glfwSetErrorCallback(errorCallback);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	// TODO: Random title as an easter egg, like Terraria
	window = glfwCreateWindow(640, 480, "Badteroids", NULL, NULL);
	if(!window) {
		std::cerr << "Could not create window" << std::endl;
		return 2;
	}

	glfwSetKeyCallback(window, keyCallback);
	// TODO: glfwSetFramebufferSizeCallback

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1); // vsync

	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);

	while(!glfwWindowShouldClose(window))
		mainLoop();

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
