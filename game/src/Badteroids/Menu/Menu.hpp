#ifndef MENU_HPP
#define MENU_HPP

#include "Main/Main.hpp"
#include "Config/Config.hpp"
#include "Pause/Pause.hpp"

class Menu {
public:
	struct State {
		enum {
			MAIN,
			CONFIG,
			PAUSE,
		};
	};

private:
	size_t state = State::MAIN;
	MainMenu main;
	ConfigMenu config;
	PauseMenu pause;

public:
	inline void init() {
		main.init();
		config.init();
		pause.init();
	}

	inline void changeState(size_t state_) { state = state_; }

	inline void move(size_t code) {
		switch(state) {
		case State::MAIN:
			main.move(code);
			break;
		case State::CONFIG:
			config.move(code);
			break;
		case State::PAUSE:
			pause.move(code);
			break;
		}
	}

	inline void draw() {
		switch(state) {
		case State::MAIN:
			main.draw();
			break;
		case State::CONFIG:
			config.draw();
			break;
		case State::PAUSE:
			pause.draw();
			break;
		}
	}
};

#endif
