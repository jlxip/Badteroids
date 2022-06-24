#include "loop.hpp"

void Loop::manage_idrs(Time dt) {
	// Tick
	if(!game->isPaused()) {
		auto it = Objects::idrawables.begin();
		while(it != Objects::idrawables.end()) {
			it->tick(dt);

			// Did it go away?
			if(it->outOfBounds())
				Objects::idrawables.markFree(it);

			++it;
		}

		Objects::idrawables.flushFree();
	}

	// Draw
	for(auto const& x : Objects::idrawables)
		x.draw();
}
