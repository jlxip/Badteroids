#include "Config.hpp"

Text& ConfigMenu::selectedText() {
	switch(selected) {
	case Selected::VSYNC:
		return tVsync;
	case Selected::AA:
		return tAA;
	case Selected::FPS:
		return tFPS;
	case Selected::BACK:
		return tBack;
	}

	// Impossible
	std::cerr << "Invalid 'selected' value in ConfigMenu" << std::endl;
	exit(2);
	return tVsync;
}

void ConfigMenu::select(size_t idx) {
	selected = idx;

	Text& sel = selectedText();
	if(sel.getStr()[0] != '{') {
		// Not selected already
		sel.getStr() = "}" + sel.getStr() + "{";
		sel.xcenter();
		sel.setGreen(true);
	}
}

void ConfigMenu::deselect() {
	Text& sel = selectedText();
	std::string& str = sel.getStr();
	str.erase(str.begin());
	str.pop_back();

	sel.xcenter();
	sel.setGreen(false);
}
