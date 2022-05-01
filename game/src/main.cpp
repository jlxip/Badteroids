#include <common.hpp>

void errorCallback(int error, const char* description) {
	std::cerr << "Error " << error << std::endl;
	std::cerr << description << std::endl;
	exit(error);
}

void keyCallback(GLFWwindow*, int, int, int, int);
void framebufferSizeCallback(GLFWwindow*, int, int);
void mainLoop();

GLFWwindow* window;

const size_t START_WIDTH = 640;
const size_t START_HEIGHT = 480;
const char winName[] = "Badteroids";

int main() {
	if(!glfwInit()) {
		std::cerr << "Could not initialize GLFW" << std::endl;
		return 1;
	}

	// Create the window
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	window = glfwCreateWindow(START_WIDTH, START_HEIGHT, winName, NULL, NULL);
	if(!window) {
		std::cerr << "Could not create window" << std::endl;
		glfwTerminate();
		return 2;
	}

	// Set some callbacks
	glfwSetErrorCallback(errorCallback);
	glfwSetKeyCallback(window, keyCallback);
	glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

	// Actually use the window
	glfwMakeContextCurrent(window);

	// Initialize GLEW
	GLenum err = glewInit();
	if(err != GLEW_OK) {
		std::cerr << "Could not initialize GLEW: " <<
			glewGetErrorString(err) << std::endl;
		glfwTerminate();
		return 3;
	}

	// Game initialization
	glfwSwapInterval(1); // VSync
	glClearColor(0.0, 0.0, 0.0, 1.0);

	// Set framebuffer
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	framebufferSizeCallback(window, width, height);

	// Go!
	while(!glfwWindowShouldClose(window))
		mainLoop();

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
