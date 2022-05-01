#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <basics/Drawable/Drawable.hpp>

class Triangle : public Drawable {
public:
	Triangle(glm::vec2 a, glm::vec2 b, glm::vec2 c);
};

#endif
