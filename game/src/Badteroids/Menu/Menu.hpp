#ifndef MENU_HPP
#define MENU_HPP

#include "Main/Main.hpp"
#include "Config/Config.hpp"

class Menu {
public:
	struct State {
		enum {
			MAIN,
			CONFIG,
		};
	};

private:
	size_t state = State::MAIN;
	MainMenu main;
	ConfigMenu config;

public:
	inline void init() {
		main.init();
		config.init();
	}

	inline void changeState(size_t state_) { state = state_; }

	inline void move(size_t code) {
		if(state == State::MAIN)
			main.move(code);
		else
			config.move(code);
	}

	inline void draw() {
		if(state == State::MAIN)
			main.draw();
		else
			config.draw();
	}
};

#endif
