#include "Badteroids.hpp"

class SquareHUD : public Drawable {
public:
	SquareHUD() {
		this->VBO_v = BasicModels::Square::VBO_v;
		this->VBO_c = VBOs::requestColor(VBOs::Color::BLACK, 4);
		this->VBO_i = BasicModels::Square::VBO_i;
		this->isize = BasicModels::Square::isize;

		this->mode = BasicModels::Square::mode;

		this->scalex = 0.5/ARX * (4+1+2);
		this->scaley = 0.5/ARY;
		this->x = 0;
		this->y = 0.9;
	}
};

static SquareHUD* squareHUD = nullptr;

void Badteroids::drawHUD() {
	// Distance to center
	if(!squareHUD)
		squareHUD = new SquareHUD;
	squareHUD->draw();

	float dist = MAX_DISTANCE + inGameTime * inGameTime * ACCELERATION/2;
	std::string sdist = f2s(dist) + " pc";
	Text tdist(sdist, 0.5, 0, 0.9);
	tdist.xcenter();
	tdist.draw();

	// HUD of each ship
	if(leftAlive())
		leftShip.drawHUD();
	if(rightAlive())
		rightShip.drawHUD();
}
