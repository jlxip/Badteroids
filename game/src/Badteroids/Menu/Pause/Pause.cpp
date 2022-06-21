#include "Pause.hpp"
#include <Badteroids/Badteroids.hpp>

extern Badteroids* game;

void PauseMenu::init() {
	tTitle = {"pause", .7, 0, +.4};
	tTitle.xcenter();

	tResume = {"resume", .7, 0, 0};
	tResume.xcenter();

	tExit = {"exit", .7, 0, -.2};
	tExit.xcenter();

	select(Selected::RESUME);
}

void PauseMenu::ok() {
	switch(selected) {
	case Selected::RESUME:
		game->switchPause();
		break;
	case Selected::EXIT:
		game->leave();
		break;
	}
}

void PauseMenu::move(size_t code) {
	switch(code) {
	case 0:
		if(selected > 0) {
			deselect();
			select(selected - 1);
		}
		break;
	case 1:
		if(selected < 1) {
			deselect();
			select(selected + 1);
		}
		break;
	case 99:
		ok();
		break;
	}
}

void PauseMenu::draw() {
	bg.draw();
	tTitle.draw();
	tResume.draw();
	tExit.draw();
}
