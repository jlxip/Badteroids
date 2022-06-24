#ifndef BORDER_HPP
#define BORDER_HPP

#include <basics/Drawable/Drawable.hpp>

class Border : public Drawable {
private:
	static constexpr float borderScale = 0.001;

public:
	Border(bool horizontal, bool first);
	inline bool collisioned(Drawable* other) override {
		IGNORE(other);
		return false;
	}
};

#endif
