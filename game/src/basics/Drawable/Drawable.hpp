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
	float r = 0.0;

	float lineWidth = 1;

	struct Inertia {
		// Velocities, units per second
		float vx = 0.0;
		float vy = 0.0;
		float w = 0.0;
	} inertia;

	TexID texture = NULL_TEXTURE;
	VBOid VBO_t = NULL_VBO;

	// True x and y
	// If all drawables are designed so that there's a vertex touching
	//   each border, then scalex=width and scaley=height, and we can
	//   do this:
	inline float tx() const { return x - scalex/2; }
	inline float ty() const { return y - scaley/2; }
	// True end x and end y
	inline float tex() const { return x + scalex/2; }
	inline float tey() const { return y + scaley/2; }

public:
	Drawable() = default;
	Drawable(const Drawable&) = default;
	Drawable(Drawable&&) = default;
	virtual ~Drawable() = default;
	Drawable& operator=(const Drawable&) = default;
	Drawable& operator=(Drawable&&) = default;

	inline void resetxy() { x = y = r = 0; }
	inline float getScalex() { return scalex; }
	inline float getScaley() { return scaley; }
	inline float getx() const { return x; }
	inline float gety() const { return y; }

	inline void setScalex(float a) { scalex = a; }
	inline void setScaley(float a) { scaley = a; }
	inline void mulScalex(float a) { scalex *= a; }
	inline void mulScaley(float a) { scaley *= a; }

	inline void setx(float a) { x = a; }
	inline void sety(float a) { y = a; }
	inline void addx(float a) { x += a; }
	inline void addy(float a) { y += a; }
	inline void addr(float a) { r += a; }

	// Regular out of bounds for garbage collection
	static constexpr float OOB_MARGIN = 0.1;
	bool outOfBounds() const;

	inline Inertia& getInertia() { return inertia; }

	void tick(float dt);
	void draw() const;

	// Collision system
	inline bool overlaps(const Drawable& o) const {
		bool cx = tex() >= o.tx() && o.tex() >= tx();
		bool cy = tey() >= o.ty() && o.tey() >= ty();
		return cx && cy;
	}

	// Must return whether object should be destroyed
	virtual bool collisioned(Drawable* _) {
		IGNORE(_);
		std::cout << "Unimplemented collisioned()!" << std::endl;
		exit(1);
		return false;
	}
};

#endif
