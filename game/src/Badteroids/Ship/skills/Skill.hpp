#ifndef SKILL_HPP
#define SKILL_HPP

#include <basics/Drawable/Drawable.hpp>

namespace Skills {
	class Skill {
	public:
		class CooldownBar : public Drawable {
		public:
			CooldownBar(size_t val);
			static void upload();
		};

	private:
		Time lastShot = -1000;
		void setHUDposition(size_t pos);

	protected:
		Drawable model;
		bool iam;

		virtual float getCooldown() = 0;
		virtual float expenseH() = 0;
		virtual float expenseO() = 0;

		float timeUntilCooldown();
		void takeResources();

	public:
		virtual ~Skill() = default;
		inline void setiam(bool v) { iam = v; }

		inline void setLeftFocused() { setHUDposition(0); }
		inline void setFocused() { setHUDposition(1); }
		inline void setRightFocused() { setHUDposition(2); }

		void draw();

		bool canFire();
		virtual void fire() = 0;
	};
};

#endif
