#include "events.hpp"
#include <events/events.hpp>
#include <Badteroids/Badteroids.hpp>

void Badteroids::registerEvents() {
	// --- MOVEMENT ---
	Keyboard::setKeyPress('A', lsLeft);
	Keyboard::setKeyPress('D', lsRight);
	Keyboard::setKeyPress('W', lsUp);
	Keyboard::setKeyPress('S', lsDown);

	// --- ACTIONS ---
	// Shoot with index finger, the most comfortable finger for the most common action
	Keyboard::setKeyPress('E', lsShoot);
}
