#include "events.hpp"

void errorCallback(int error, const char* description) {
	std::cerr << "Error " << error << std::endl;
	std::cerr << description << std::endl;
	exit(error);
}
