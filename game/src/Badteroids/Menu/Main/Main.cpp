#include "Main.hpp"
#include <Badteroids/Badteroids.hpp>

extern Badteroids* game;

MainMenu::MainMenu() {
	tTitle = {"bAdteRoids", .7, 0, +.6};
	tTitle.xcenter();

	tPlay = {"play", .7, 0, +.2};
	tPlay.xcenter();

	tConfig = {"configuration", .7, 0, -.1};
	tConfig.xcenter();

	tExit = {"exit", .7, 0, -.4};
	tExit.xcenter();

	select(Selected::PLAY);
}

void MainMenu::ok() {
	switch(selected) {
	case Selected::PLAY:
		std::cout << "PLAY" << std::endl;
		game->startGame();
		break;
	case Selected::CONFIG:
		break;
	case Selected::EXIT:
		break;
	}
}

void MainMenu::move(size_t code) {
	switch(code) {
	case 0:
		if(selected > 0) {
			deselect();
			select(selected - 1);
		}
		break;
	case 1:
		if(selected < 2) {
			deselect();
			select(selected + 1);
		}
		break;
	case 99:
		ok();
		break;
	}
}

void MainMenu::draw() {
	tTitle.draw();
	tPlay.draw();
	tConfig.draw();
	tExit.draw();
}
