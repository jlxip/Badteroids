#include "models/ShipModel.hpp"
#include <loop/objects.hpp>

class Ship {
private:
	ObjID model;
	const float shipScalex = 0.02;
	const float shipScaley = 0.04;

public:
	Ship();
	inline ObjID getModel() const { return model; }
};
