#include "Pause.hpp"

Text& PauseMenu::selectedText() {
	switch(selected) {
	case Selected::RESUME:
		return tResume;
	case Selected::EXIT:
		return tExit;
	}

	// Impossible
	std::cerr << "Invalid 'selected' value in MainMenu" << std::endl;
	exit(2);
	return tResume;
}

void PauseMenu::select(size_t idx) {
	selected = idx;

	Text& sel = selectedText();
	if(sel.getStr()[0] != '{') {
		// Not selected already
		sel.getStr() = "}" + sel.getStr() + "{";
		sel.xcenter();
		sel.setGreen(true);
	}
}

void PauseMenu::deselect() {
	Text& sel = selectedText();
	std::string& str = sel.getStr();
	str.erase(str.begin());
	str.pop_back();

	sel.xcenter();
	sel.setGreen(false);
}
