#ifndef EVENTS_HPP
#define EVENTS_HPP

#include <common.hpp>

void errorCallback(int error, const char* description);
void keyCallback(GLFWwindow*, int, int, int, int);
void framebufferSizeCallback(GLFWwindow*, int, int);

#endif
