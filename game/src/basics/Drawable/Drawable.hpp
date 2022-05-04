#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <common.hpp>
#include <vector>
#include <basics/VBOs/VBOs.hpp>
#include <basics/Textures/Textures.hpp>

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

	TexID texture = NULL_TEXTURE;
	VBOid VBO_t = NULL_VBO;

public:
	inline float getx() const { return x; }
	inline float gety() const { return y; }

	inline void mulScalex(float a) { scalex *= a; }
	inline void mulScaley(float a) { scaley *= a; }
	inline void addx(float a) { x += a; }
	inline void addy(float a) { y += a; }

	// Regular out of bounds for garbage collection
	static constexpr float OOB_MARGIN = 0.1;
	inline bool outOfBounds() const {
		if(x > (1+OOB_MARGIN) || y > (1+OOB_MARGIN))
			return true;

		// If all drawables are designed so that there's at least a vertex
		//   touching each border, then scalex=width and scaley=height, and
		//   we can do this:
		if((x + scalex) < (-1-OOB_MARGIN))
			return true;
		if((y + scaley) < (-1-OOB_MARGIN))
			return true;

		return false;
	}

	inline Inertia& getInertia() { return inertia; }

	void tick(float dt);
	void draw() const;
};

#endif
