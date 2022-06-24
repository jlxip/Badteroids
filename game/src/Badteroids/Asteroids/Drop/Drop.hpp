#ifndef DROP_HPP
#define DROP_HPP

#include <basics/Drawable/Drawable.hpp>

class Drop : public Drawable {
public:
	struct Type {
		enum {
			HYDROGEN,
			OXYGEN,
		};
	};

private:
	size_t type;

	static constexpr float SIZE = 0.2;

public:
	Drop(float x, float y, float dy, size_t type);

	bool collisioned(Drawable* other) override;
};

#endif
