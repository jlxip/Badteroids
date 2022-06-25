#include "Ship.hpp"
#include <basics/Text/Text.hpp>

void Ship::drawHUD() {
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
