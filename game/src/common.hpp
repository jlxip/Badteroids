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

typedef double Time; // Just to avoid "float" mistakes
extern Time now;

template<typename Base, typename T>
inline bool instanceof(const T* ptr) {
	return dynamic_cast<const Base*>(ptr) != nullptr;
}

#include <sstream>

inline std::string f2s(float x) {
	std::ostringstream out;
	out.precision(2);
	out << std::fixed << x;
	return out.str();
}

// Some constants regarding the game, which have to be here
constexpr Time GAME_DURATION = 5 * 60;
constexpr size_t N_SKILLS = 2;

#endif
