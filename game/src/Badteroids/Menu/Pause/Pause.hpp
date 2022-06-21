#ifndef PAUSE_HPP
#define PAUSE_HPP

#include <basics/Text/Text.hpp>
#include <basics/models/Square/Square.hpp>
#include <basics/Drawable/Drawable.hpp>

class PauseMenu {
private:
	struct Selected {
		enum {
			RESUME,
			EXIT,
		};
	};

	class BG : public Drawable {
	public:
		BG() {
			this->VBO_v = BasicModels::Square::VBO_v;
			this->VBO_c = VBOs::requestBlackVBO(BasicModels::Square::vsize);
			this->VBO_i = BasicModels::Square::VBO_i;
			this->isize = BasicModels::Square::isize;
			this->mode = BasicModels::Square::mode;
			this->scalex = this->scaley = 0.5;
		}
	} bg;

	Text tTitle, tResume, tExit;

	size_t selected;
	Text& selectedText();
	void select(size_t idx);
	void deselect();

	void ok();

public:
	void init();
	void move(size_t code);
	void draw();
};

#endif
