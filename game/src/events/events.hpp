#ifndef EVENTS_HPP
#define EVENTS_HPP

#include <common.hpp>

void errorCallback(int error, const char* description);

namespace Keyboard {
	typedef void (*KeyEvent)();
	void setKeyPress(size_t c, KeyEvent ke);
	void setKeyRelease(size_t c, KeyEvent ke);
}
void keyCallback(GLFWwindow*, int, int, int, int);

void framebufferSizeCallback(GLFWwindow*, int, int);

#endif
