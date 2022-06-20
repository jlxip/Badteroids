#include "Main.hpp"

Text& MainMenu::selectedText() {
	switch(selected) {
	case Selected::PLAY:
		return tPlay;
	case Selected::CONFIG:
		return tConfig;
	case Selected::EXIT:
		return tExit;
	}

	// Impossible
	std::cerr << "Invalid 'selected' value in MainMenu" << std::endl;
	exit(2);
	return tPlay;
}

void MainMenu::select(size_t idx) {
	selected = idx;

	Text& sel = selectedText();
	if(sel.getStr()[0] != '{') {
		// Not selected already
		sel.getStr() = "}" + sel.getStr() + "{";
		sel.xcenter();
		sel.setGreen(true);
	}
}

void MainMenu::deselect() {
	Text& sel = selectedText();
	std::string& str = sel.getStr();
	str.erase(str.begin());
	str.pop_back();

	sel.xcenter();
	sel.setGreen(false);
}
