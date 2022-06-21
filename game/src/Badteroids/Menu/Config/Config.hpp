#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <basics/Text/Text.hpp>

class ConfigMenu {
private:
	struct Selected {
		enum {
			VSYNC,
			AA,
			FPS,
			BACK,
			N_SELECTED,
		};
	};

	bool restartRequired = false;

	Text tTitle, tVsync, tAA, tFPS, tBack, tRestart;

	size_t selected;
	Text& selectedText();
	void select(size_t idx);
	void deselect();

	void ok();

public:
	void init();
	void move(size_t code);
	void draw();
};

#endif
