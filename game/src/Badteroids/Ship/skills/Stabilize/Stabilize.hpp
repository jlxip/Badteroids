#ifndef STABILIZE_HPP
#define STABILIZE_HPP

#include "../Skill.hpp"

namespace Skills {
	class Stabilize : public Skill {
	private:
		inline float getCooldown() override { return 5; }
		inline float expenseH() override { return 0; }
		inline float expenseO() override { return 10; }

	public:
		class Model : public Drawable {
		public:
			Model();
			static void upload();
		};

		Stabilize();

		void fire() override;
	};
};

#endif
