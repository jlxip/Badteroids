#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <common.hpp>
#include <vector>
#include <basics/VBOs/VBOs.hpp>

// Basic drawable object that does NOT change in shape

class Drawable {
protected:
	VBOid VBO_v = NULL_VBO; // Vertices
	VBOid VBO_c = NULL_VBO; // Colors
	VBOid VBO_i = NULL_VBO; // Triangles (indices)

	size_t isize = 0; // How many indices?

	size_t mode = GL_LINE_STRIP;

	float scalex = 1.0;
	float scaley = 1.0;
	float movex = 0.0;
	float movey = 0.0;

public:
	inline void mulScalex(float a) { scalex *= a; }
	inline void mulScaley(float a) { scaley *= a; }
	inline void addx(float a) { movex += a; }
	inline void addy(float a) { movey += a; }

	void draw() const;
};

#endif
