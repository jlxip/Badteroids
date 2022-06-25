#ifndef SHIP_RELATED_EVENT_HPP
#define SHIP_RELATED_EVENT_HPP

#include <Badteroids/TimedEvents/TimedEvents.hpp>

namespace TimedEvents {
	struct ShipRelated {
		TimedEvent base;
		float mulDeviation = 0;

		ShipRelated() {
			base.isShip = true;
		}
	};
};

#endif
