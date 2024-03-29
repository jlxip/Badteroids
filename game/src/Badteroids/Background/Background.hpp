#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include <common.hpp>
#include <basics/Drawable/Drawable.hpp>
#include <basics/Textures/Textures.hpp>
#include <loop/objects.hpp>

class Background {
public:
	class BGDraw : public Drawable {
	private:
		float velocity = .3; // Windows per second
	public:
		static void upload();
		BGDraw();
		inline void setTexID(TexID id) { this->texture = id; }
		void textick(float dt);
	};

private:
	uint8_t* texture = nullptr;
	size_t width = 0;
	size_t height = 0;

	const float density = 0.01;
	const float brightness = 0.5;

	TexID tex = NULL_TEXTURE;
	BGDraw drawable;

public:
	void generate(size_t width, size_t height);
	void upload();

	inline BGDraw& getDraw() { return drawable; }
};

#endif
