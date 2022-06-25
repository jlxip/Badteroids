#include "Ship.hpp"
#include <basics/Text/Text.hpp>

void Ship::drawHUD() {
	const float y = 0.8;
	float x;
	if(iam == LEFT_SHIP)
		x = -0.9;
	else
		x = 0.7;

	// H2
	std::string hstr = "h2=" + f2s(resources.h);
	Text(hstr, 0.5, x, y).draw();

	// O2
	std::string ostr = "o2=" + f2s(resources.o);
	Text(ostr, 0.5, x, y - 0.1).draw();

	// Skils
	if(selectedSkill > 0) {
		skills[selectedSkill-1]->setLeftFocused();
		skills[selectedSkill-1]->draw();
	}
	skills[selectedSkill]->setFocused();
	skills[selectedSkill]->draw();
	if(selectedSkill < availableSkills-1) {
		skills[selectedSkill+1]->setRightFocused();
		skills[selectedSkill+1]->draw();
	}
}
