#ifndef EVENT_HORIZON_HPP
#define EVENT_HORIZON_HPP

#include <basics/Drawable/Drawable.hpp>

class EventHorizon : public Drawable {
public:
	// Windows per second (same as BGDraw)
	static constexpr float velocity = .6;

	EventHorizon();

	void customTick(Time dt);
	void reset();
};


#endif
