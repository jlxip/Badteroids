#ifndef SHIP_HPP
#define SHIP_HPP

#include "Laser/Laser.hpp"
#include <loop/objects.hpp>
#include "skills/Skill.hpp"

// A Ship object lives in one side of the screen
// So, for the left ship, (1, -1) actually corresponds to Badteroids' (0.5, -1)

#define LEFT_SHIP false
#define RIGHT_SHIP true

class Ship {
private:
	ObjID obj = 0;
	static constexpr float shipScalex = 0.01;
	static constexpr float shipScaley = 0.02;

	static constexpr float velocityPerPress = 0.1;
	float maxDeviation = velocityPerPress * 0.05; // 5%
	bool iam;

	// Some bounds
	float minx, maxx; // Derived from "iam"
	static constexpr float miny = -1;
	static constexpr float maxy = +1;

	// Resources
	struct {
		float h = 100;
		float o = 100;
	} resources;
	static constexpr float HYDROGEN_BURN = 2;
	static constexpr float OXYGEN_PER_HYDROGEN = 1./4;
	static constexpr float H_PER_DROP = 50;
	static constexpr float O_PER_DROP = 50;

	// Skills
	std::vector<Skills::Skill*> skills;
	size_t availableSkills = 1;
	size_t selectedSkill = 0;

public:
	Ship(bool iam_);
	void init();
	void reset();
	inline bool alive() {
		if(!obj)
			return false;
		if(Objects::cidrawablesp.freed(obj))
			return (obj = 0);
		return true;
	}

	inline bool getiam() const { return iam; }

	void tick();

	inline Drawable& getModel() { return *Objects::cidrawablesp[obj]; }
	void drawHUD();

	inline void addH(float v=H_PER_DROP) {
		resources.h += v;
		if(resources.h > 100)
			resources.h = 100;
	}

	inline void addO(float v=O_PER_DROP) {
		resources.o += v;
		if(resources.o > 100)
			resources.o = 100;
	}

	inline void addSkill() { ++availableSkills; }

	inline float getH() { return resources.h; }
	inline float getO() { return resources.o; }

	void _move(float dx, float dy);
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void shoot();

	inline void skillFire() {
		auto* skill = skills[selectedSkill];
		if(skill->canFire())
			skill->fire();
	}
	inline void skillLeft() {
		if(selectedSkill > 0)
			--selectedSkill;
	}

	inline void skillRight() {
		if(selectedSkill < availableSkills-1)
			++selectedSkill;
	}

	inline void destabilize(float factor) { maxDeviation *= factor; }
};

#endif
