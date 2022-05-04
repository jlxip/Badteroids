#ifndef SQUARE_HPP
#define SQUARE_HPP

// A few objects are just resized squares
// Why not use the same VBOs?

#include <basics/VBOs/VBOs.hpp>

namespace BasicModels {
	namespace Square {
		const size_t vsize = 4;
		const size_t isize = 3*2; // Two triangles
		const GLenum mode = GL_TRIANGLES;

		extern VBOid VBO_v;
		extern VBOid VBO_i;

		void upload();
	}
}

#endif
