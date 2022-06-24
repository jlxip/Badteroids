#include "objects.hpp"

ObjID Objects::monotonic = 1;

Objects::Array<Drawable>
	Objects::drawables,
	Objects::idrawables;

Objects::Array<Drawable*>
	Objects::cidrawablesp;
