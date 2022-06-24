#ifndef DUMMY_SHIP_HPP
#define DUMMY_SHIP_HPP

#include "../ShipModel.hpp"

namespace ShipModels {
	class Dummy : public ShipModel {
	public:
		static void upload();
		Dummy();
	};
};

#endif
