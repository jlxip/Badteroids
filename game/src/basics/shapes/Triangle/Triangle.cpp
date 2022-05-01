#include "Triangle.hpp"

Triangle::Triangle(glm::vec2 a, glm::vec2 b, glm::vec2 c) {
	this->vertices = {a, b, c};
	this->indices = {0, 1, 2};
}
