#ifndef MAIN_HPP
#define MAIN_HPP

#include <basics/Text/Text.hpp>

class MainMenu {
private:
	struct Selected {
		enum {
			PLAY,
			CONFIG,
			EXIT,
		};
	};

	Text tTitle, tPlay, tConfig, tExit;

	size_t selected;
	Text& selectedText();
	void select(size_t idx);
	void deselect();

	void ok();

public:
	MainMenu();

	void move(size_t code);
	void draw();
};

#endif
