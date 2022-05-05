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
}
