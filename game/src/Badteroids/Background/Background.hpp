#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include <common.hpp>
#include <basics/Drawable/Drawable.hpp>
#include <basics/Textures/Textures.hpp>
#include <loop/objects.hpp>

class Background {
public:
	class BGDraw : public Drawable {
	public:
		static void upload();
		BGDraw();
		inline void setTexID(TexID id) { this->texture = id; }
	};

private:
	unsigned char* texture = nullptr;
	size_t width = 0;
	size_t height = 0;

	const float density = 0.25;
	const float brightness = 0.125;

	TexID tex = NULL_TEXTURE;
	BGDraw drawable;

public:
	void generate(size_t width, size_t height);
	void upload();

	inline BGDraw& getDraw() { return drawable; }
};

#endif
