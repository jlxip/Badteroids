#ifndef MENU_HPP
#define MENU_HPP

#include "Main/Main.hpp"

class Menu {
private:
	// Common
	struct State {
		enum {
			MAIN,
			CONFIG,
		};
	};

	size_t state = State::MAIN;
	MainMenu main;

public:
	inline void move(size_t code) {
		if(state == State::MAIN)
			main.move(code);
	}

	inline void draw() {
		if(state == State::MAIN)
			main.draw();
	}
};

#endif
