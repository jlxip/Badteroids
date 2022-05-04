#ifndef TEXT_HPP
#define TEXT_HPP

// Gotta draw some text

#include <string>

class Text {
public:
	struct Fonts {
		enum { HACK, N_FONTS };

		static constexpr char pathHack[] = "assets/fonts/Hack.bmp";

		static void upload();
	};

private:
	Text(const std::string& str, size_t font=Fonts::HACK);
};

#endif
