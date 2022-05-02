#include <events/events.hpp>

void preparations();
void mainLoop();

GLFWwindow* window;

const size_t START_WIDTH = 640;
const size_t START_HEIGHT = 480;
const char winName[] = "Badteroids";

const size_t MSAAxn = 16;

int main() {
	std::cout << "Initializing window and OpenGL context" << std::endl;
	if(!glfwInit()) {
		std::cerr << "Could not initialize GLFW" << std::endl;
		return 1;
	}

	// Create the window
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_SAMPLES, MSAAxn); // Multisampling anti-aliasing
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

	// Set framebuffer
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	framebufferSizeCallback(window, width, height);



	std::cout << "Last minute preparations..." << std::endl;
	preparations();

	// Go!
	std::cout << "Starting main loop" << std::endl;
	while(!glfwWindowShouldClose(window))
		mainLoop();

	std::cout << "Thanks for playing!" << std::endl;
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
