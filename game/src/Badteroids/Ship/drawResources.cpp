#include "Ship.hpp"
#include <basics/Text/Text.hpp>
#include <sstream>

static std::string f2s(float x) {
	std::ostringstream out;
	out.precision(2);
	out << std::fixed << x;
	return out.str();
}

void Ship::drawResources() {
	const float y = 0.8;
	float x;
	if(iam == LEFT_SHIP)
		x = -0.9;
	else
		x = 0.7;

	std::string hstr = "h2=" + f2s(resources.h);
	Text(hstr, 0.5, x, y).draw();

	std::string ostr = "o2=" + f2s(resources.o);
	Text(ostr, 0.5, x, y-0.1).draw();
}
