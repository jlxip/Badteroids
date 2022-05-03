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
	float x = 0.0;
	float y = 0.0;

	struct Inertia {
		// Velocities, units per second
		float vx = 0.0;
		float vy = 0.0;
	} inertia;

public:
	inline void mulScalex(float a) { scalex *= a; }
	inline void mulScaley(float a) { scaley *= a; }
	inline void addx(float a) { x += a; }
	inline void addy(float a) { y += a; }

	inline Inertia& getInertia() { return inertia; }

	void tick(float dt);
	void draw() const;
};

#endif
