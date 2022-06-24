#include "loop.hpp"
#include <unordered_set>

void Loop::manage_cidrs(Time dt) {
	if(!game->isPaused()) {
		// Tick
		auto it = Objects::cidrawablesp.begin();
		while(it != Objects::cidrawablesp.end()) {
			(*it)->tick(dt);

			// Did it go away?
			if((*it)->outOfBounds()) {
				delete *it;
				Objects::cidrawablesp.markFree(it);
			}

			++it;
		}

		Objects::cidrawablesp.flushFree();

		// Check collisions. This is AABB. Slow? Maybe
		std::vector<std::pair<ObjID, ObjID>> colls;
		it = Objects::cidrawablesp.begin();
		while(it != Objects::cidrawablesp.end()) {
			auto it2 = it; ++it2;
			while(it2 != Objects::cidrawablesp.end()) {
				if((*it)->overlaps(**it2)) {
					colls.push_back({
							Objects::cidrawablesp.getID(it),
							Objects::cidrawablesp.getID(it2)
						});
				}
				++it2;
			}
			++it;
		}

		// Resolve collisions
		std::unordered_set<ObjID> freeThis;
		for(auto const& x : colls) {
			auto f = Objects::cidrawablesp.get(x.first);
			auto s = Objects::cidrawablesp.get(x.second);
			if(f->collisioned(s))
				freeThis.insert(x.first);
			if(s->collisioned(f))
				freeThis.insert(x.second);
		}

		// Free if collision resolution said so
		for(auto x : freeThis) {
			delete Objects::cidrawablesp.get(x);
			Objects::cidrawablesp.free(x);
		}
	}

	// Draw
	for(auto const& x : Objects::cidrawablesp)
		x->draw();
}
