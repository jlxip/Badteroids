#ifndef DESTABILIZE_HPP
#define DESTABILIZE_HPP

#include "../Skill.hpp"

namespace Skills {
	class Destabilize : public Skill {
	private:
		inline float getCooldown() override { return 20; }
		inline float expenseH() override { return 20; }
		inline float expenseO() override { return 5; }

		static constexpr Time duration = 10;
		static constexpr float factor = 50;

	public:
		class Model : public Drawable {
		public:
			Model();
			static void upload();
		};

		Destabilize();

		void fire() override;
	};
};

#endif
