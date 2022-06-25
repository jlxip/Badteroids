#include "Badteroids.hpp"
#include "Bar/Bar.hpp"
#include "Border/Border.hpp"

extern GLFWwindow* window;

Badteroids::Badteroids() {
	// Get me a background
	glfwGetFramebufferSize(window, &width, &height);
	background.generate(width, height);
	background.upload();

	// Key presses
	registerEvents();
}

void Badteroids::init() {
	// Initialize menu
	menu.init();
}

void Badteroids::startGame() {
	inMenu = false;
	playing = true;

	Objects::cidrawablesp.alloc(new Bar);
	Objects::cidrawablesp.alloc(new Border(false, true)); // Left border
	Objects::cidrawablesp.alloc(new Border(false, false)); // Right
	Objects::cidrawablesp.alloc(new Border(true, true)); // Top
	Objects::cidrawablesp.alloc(new Border(true, false)); // Bottom

	// Reset ships
	leftShip.reset();
	rightShip.reset();
	leftAst.reset();
	rightAst.reset();

	eventHorizon.reset();
	stage = Stage::BEGINNING;
	inGameTime = 0;
}

void Badteroids::leave() {
	inMenu = true;
	paused = playing = false;
	menu.changeState(Menu::State::MAIN);

	Objects::drawables.clear();
	Objects::idrawables.clear();
	for(auto x : Objects::cidrawablesp)
		delete x;
	Objects::cidrawablesp.clear();

	someoneWon = false;
}

void Badteroids::exit() {
	glfwSetWindowShouldClose(window, true);
}

void Badteroids::win(bool who) {
	if(!someoneWon) {
		someoneWon = true;
		whoWon = who;
	}
}

void Badteroids::cheatSkip() {
	if(inGameTime > tEventHorizon) {
	} else if(inGameTime > tBreak) {
		inGameTime = tEventHorizon - 5;
	} else if(inGameTime > tAsteroidBelt) {
		inGameTime = tBreak - 5;
	} else {
		inGameTime = tAsteroidBelt - 5;
	}
}

void Badteroids::veryFirstTick(Time dt) {
	if(playing && stage == Stage::EVENT_HORIZON) {
		if(!paused)
			eventHorizon.customTick(dt);
		eventHorizon.draw();
	}
}

void Badteroids::tick(Time dt) {
	if(playing && !paused)
		inGameTime += dt;

	if(inGameTime > tEventHorizon) {
		stage = Stage::EVENT_HORIZON;
		leftAst.disable();
		rightAst.disable();
	} else if(inGameTime > tBreak) {
		// Get out of asteroid belt
		stage = Stage::BREAK;
		leftAst.setAsteroidBelt(false);
		rightAst.setAsteroidBelt(false);
	} else if(inGameTime > tAsteroidBelt) {
		stage = Stage::ASTEROID_BELT;
		leftAst.setAsteroidBelt(true);
		rightAst.setAsteroidBelt(true);
	}

	leftAst.tick();
	rightAst.tick();

	leftShip.tick();
	rightShip.tick();

	if(inGameTime >= GAME_DURATION)
		win(false);
}

void Badteroids::veryLastTick() {
	if(someoneWon) {
		std::string stext = "left";
		if(whoWon)
			stext = "right";
		stext += " player won!";

		Text text(stext, 0.7, 0, 0);
		text.xcenter();
		text.setRed(true);
		text.draw();
	}
}
