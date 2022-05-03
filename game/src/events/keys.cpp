#include "events.hpp"

#define MAX_KEYS 256
static void* presses[MAX_KEYS] = {nullptr};
static void* releases[MAX_KEYS] = {nullptr};

void Keyboard::setKeyPress(size_t c, KeyEvent ke) { presses[c] = (void*)ke; }
void Keyboard::setKeyRelease(size_t c, KeyEvent ke) { releases[c] = (void*)ke; }

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	// TODO: pause when ESC
	if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
		return;
	}

	IGNORE(scancode);
	IGNORE(mods);

	// Weird key? Just ignore
	if(key >= MAX_KEYS)
		return;

	// Only presses
	void* ptr = nullptr;
	switch(action) {
	case GLFW_PRESS:
		ptr = presses[key];
		break;
	case GLFW_RELEASE:
		ptr = releases[key];
		break;
	default:
		return;
	}

	// No event assigned?
	if(!ptr)
		return;

	((Keyboard::KeyEvent)ptr)();
}
