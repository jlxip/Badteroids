#include "Config.hpp"
#include <Badteroids/Badteroids.hpp>
#include <Config/Config.hpp>

extern Badteroids* game;
extern Config globalConfig;

static const char* ovsync = "  vsync >";
static const char* oflex = "< flex mode  ";

static const char* ofpsoff = "  fps off >";
static const char* ofpson = "< fps on  ";

static const char* onoaa = "  no aa >";
static const char* omsaax2 = "< msaax2 >";
static const char* omsaax4 = "< msaax4 >";
static const char* omsaax8 = "< msaax8 >";
static const char* omsaax16 = "< msaax16 >";
static const char* omsaax32 = "< msaax32  ";
static const char* oaa[6] = {onoaa, omsaax2, omsaax4, omsaax8, omsaax16, omsaax32};

void ConfigMenu::init() {
	tTitle = {"settings", .7, 0, +.6};
	tTitle.xcenter();

	bool isVSync = globalConfig.isVSync();
	tVsync = {isVSync ? ovsync : oflex, .7, 0, +.2};
	tVsync.xcenter();

	size_t aa = globalConfig.getMSAAxn();
	tAA = {oaa[aa], .7, 0, 0};
	tAA.xcenter();

	bool showFPS = globalConfig.getFPS();
	tFPS = {showFPS ? ofpson : ofpsoff, .7, 0, -.2};
	tFPS.xcenter();

	tBack = {"back", .7, 0, -.4};
	tBack.xcenter();

	tRestart = {"restart required", .5, 0, -.8};
	tRestart.xcenter();
	tRestart.setRed(true);

	select(Selected::VSYNC);
}

void ConfigMenu::ok() {
	if(selected != Selected::BACK)
		return;

	init();
	game->getMenu().changeState(Menu::State::MAIN);
}

// This is very much improvable, I'm aware
void ConfigMenu::move(size_t code) {
	switch(code) {
	case 0: // Up
		if(selected > 0) {
			deselect();
			select(selected - 1);
		}
		break;
	case 1: // Down
		if(selected < Selected::N_SELECTED-1) {
			deselect();
			select(selected + 1);
		}
		break;
	case 2: // Left
		switch(selected) {
		case Selected::VSYNC:
			if(!globalConfig.isVSync()) {
				// Change to VSync
				globalConfig.setVSync(true);
				deselect();
				tVsync.getStr() = ovsync;
				select(Selected::VSYNC);
			}
			break;
		case Selected::AA:
			if(globalConfig.getMSAAxn() > 0) {
				auto newval = globalConfig.getMSAAxn() - 1;
				globalConfig.setMSAAxn(newval);
				deselect();
				tAA.getStr() = oaa[newval];
				select(Selected::AA);
				restartRequired = true;
			}
			break;
		case Selected::FPS:
			if(globalConfig.getFPS()) {
				// Change to FPS off
				globalConfig.setFPS(false);
				deselect();
				tFPS.getStr() = ofpsoff;
				select(Selected::FPS);
			}
			break;
		}
		break;
	case 3: // Right
		switch(selected) {
		case Selected::VSYNC:
			if(globalConfig.isVSync()) {
				// Change to flex
				globalConfig.setVSync(false);
				deselect();
				tVsync.getStr() = oflex;
				select(Selected::VSYNC);
			}
			break;
		case Selected::AA:
			if(globalConfig.getMSAAxn() < 5) {
				auto newval = globalConfig.getMSAAxn() + 1;
				globalConfig.setMSAAxn(newval);
				deselect();
				tAA.getStr() = oaa[newval];
				select(Selected::AA);
				restartRequired = true;
			}
			break;
		case Selected::FPS:
			if(!globalConfig.getFPS()) {
				// Change to FPS on
				globalConfig.setFPS(true);
				deselect();
				tFPS.getStr() = ofpson;
				select(Selected::FPS);
			}
			break;
		}
		break;
	case 99:
		ok();
		break;
	}
}

void ConfigMenu::draw() {
	tTitle.draw();
	tVsync.draw();
	tAA.draw();
	tFPS.draw();
	tBack.draw();
	if(restartRequired)
		tRestart.draw();
}
