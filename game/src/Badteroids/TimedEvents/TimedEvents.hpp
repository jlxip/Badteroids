#ifndef TIMED_EVENTS
#define TIMED_EVENTS

#include <common.hpp>
#include <set>

namespace TimedEvents {
	struct TimedEvent {
		Time deadline = 0;
		bool isShip = false;

		inline bool operator<(const TimedEvent& o) const {
			return deadline < o.deadline;
		}
	};

	extern std::set<TimedEvent*> events;
};

#endif
