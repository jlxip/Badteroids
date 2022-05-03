#include "events.hpp"
#include <events/events.hpp>
#include <Badteroids/Badteroids.hpp>

void Badteroids::registerEvents() {
	Keyboard::setKeyPress('A', lsLeft);
	Keyboard::setKeyPress('D', lsRight);
	Keyboard::setKeyPress('W', lsUp);
	Keyboard::setKeyPress('S', lsDown);
}
