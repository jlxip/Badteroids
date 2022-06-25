#include "events.hpp"
#include <events/events.hpp>
#include <Badteroids/Badteroids.hpp>

void Badteroids::registerEvents() {
	// --- MOVEMENT ---
	Keyboard::setKeyPress('A', lsLeft);
	Keyboard::setKeyPress('D', lsRight);
	Keyboard::setKeyPress('W', lsUp);
	Keyboard::setKeyPress('S', lsDown);

	Keyboard::setKeyPress('J', rsLeft);
	Keyboard::setKeyPress('L', rsRight);
	Keyboard::setKeyPress('I', rsUp);
	Keyboard::setKeyPress('K', rsDown);

	// --- ACTIONS ---
	// Shoot with index finger, the most comfortable finger
	//   for the most common action. Both use their right hand.
	Keyboard::setKeyPress('Q', lsShoot);
	Keyboard::setKeyPress('U', rsShoot);
	// Skills
	Keyboard::setKeyPress('E', lsSkillFire);
	Keyboard::setKeyPress('Z', lsSkillLeft);
	Keyboard::setKeyPress('X', lsSkillRight);

	Keyboard::setKeyPress('O', rsSkillFire);
	Keyboard::setKeyPress('M', rsSkillLeft);
	Keyboard::setKeyPress(GLFW_KEY_COMMA, rsSkillRight);

	// --- META ---
	Keyboard::setKeyPress(GLFW_KEY_UP, _menuUp);
	Keyboard::setKeyPress(GLFW_KEY_DOWN, _menuDown);
	Keyboard::setKeyPress(GLFW_KEY_LEFT, _menuLeft);
	Keyboard::setKeyPress(GLFW_KEY_RIGHT, _menuRight);
	Keyboard::setKeyPress(GLFW_KEY_ENTER, _menuEnter);

	Keyboard::setKeyPress(GLFW_KEY_LEFT_CONTROL, _pause);
	Keyboard::setKeyPress(GLFW_KEY_RIGHT_CONTROL, _pause);

	Keyboard::setKeyPress(GLFW_KEY_F11, _skip);
	Keyboard::setKeyPress(GLFW_KEY_F12, _godMode);
}
