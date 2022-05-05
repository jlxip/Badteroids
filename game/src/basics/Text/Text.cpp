#include "Text.hpp"
#include "Font/Font.hpp"

static Font fonts[Text::Fonts::N_FONTS];

static const char pathHack[] = "assets/fonts/Hack.bmp";

void Text::Fonts::upload() {
	fonts[HACK].load(pathHack);
}

// --- Text ---
Text::Text(const std::string& str, size_t font) {
	// Vertices: how many? Four (quad) for each letter.

	// This is left unfinished for now
	IGNORE(str);
	IGNORE(font);
}
