#include "Config.hpp"
#include <fstream>
#include <Badteroids/Badteroids.hpp>

extern Badteroids* game;

void Config::setDefaults() {
	data.vsync = true;
	data.msaaxn = 4;
	data.fps = false;
}

void Config::load(bool doRefresh) {
	// File exists?
	std::ifstream file;
	file.open(configFile);
	if(!file.good()) {
		setDefaults();
		save(doRefresh);
		return;
	}
	file.read((char*)&data, sizeof(data));
	file.close();

	if(doRefresh)
		refresh();
}

// Apply config
void Config::refresh() {
	glfwSwapInterval(data.vsync ? 1 : 0);
	if(game)
		game->setShowFPS(data.fps);
}

void Config::save(bool doRefresh) {
	if(doRefresh)
		refresh();

	std::ofstream file;
	file.open(configFile);
	if(!file.good()) {
		std::cout << "Could not open " << configFile << std::endl;
		exit(9);
	}
	file.write((char*)&data, sizeof(data));
	file.close();
}
