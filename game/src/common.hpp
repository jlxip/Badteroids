#ifndef COMMON_HPP
#define COMMON_HPP

#include <cstdint>
#include <iostream>
#include <unistd.h>

#define IGNORE(x) ((void)x)

// I'm perfectly aware this makes compiling much slower
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

// Forced aspect ratio
#define ARX 16
#define ARY 9

#endif
