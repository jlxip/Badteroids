#include "skills.hpp"

void Skills::upload() {
	Skill::CooldownBar::upload();
	Stabilize::Model::upload();
	Destabilize::Model::upload();
}
