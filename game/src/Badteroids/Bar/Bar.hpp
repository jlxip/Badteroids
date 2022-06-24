#ifndef BAR_HPP
#define BAR_HPP

#include <basics/Drawable/Drawable.hpp>

class Bar : public Drawable {
private:
	static constexpr float barScaley = 0.001;

public:
	static void upload();
	Bar();

	inline bool collisioned(Drawable* other) override {
		IGNORE(other);
		return false;
	}
};

#endif
