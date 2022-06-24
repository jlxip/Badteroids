#include "Asteroid.hpp"
#include <unordered_map>
#include <vector>
#include <cmath>
#include <Badteroids/Ship/Laser/Laser.hpp>
#include <loop/objects.hpp>
#include "../Drop/Drop.hpp"

static std::unordered_map<size_t, std::vector<glm::vec2>> vertices;
static std::unordered_map<size_t, std::vector<Index>> indices;

static std::unordered_map<size_t, VBOid> VBOsv, VBOsi;

static const float r = 0.5; // Polygon radius
static void generate(size_t n) {
	for(size_t i=0; i<n; ++i) {
		float x = r * cos(2 * M_PI * i / n);
		float y = r * sin(2 * M_PI * i / n);
		vertices[n].push_back({x, y});
	}

	for(size_t i=0; i<n; ++i) {
		for(size_t j=i+1; j<n; ++j) {
			indices[n].push_back(i);
			indices[n].push_back(j);
		}
	}

	VBOsv[n] = VBOs::makeVertices(vertices[n].data(), n);
	VBOsi[n] = VBOs::makeIndices(indices[n].data(), n*(n-1));
}

void Asteroid::setVertices(size_t n_) {
	n = n_;
	if(vertices.find(n) == vertices.end())
		generate(n);

	this->VBO_v = VBOsv[n];
	this->VBO_i = VBOsi[n];
	this->isize = n*(n-1);

	size_t color = VBOs::Color::BLACK;
	switch(this->type) {
	case Type::REGULAR:
		color = VBOs::Color::GREEN; break;
	case Type::HYDROGEN:
		color = VBOs::Color::WHITE; break;
	case Type::OXYGEN:
		color = VBOs::Color::LIGHTBLUE; break;
	}

	this->VBO_c = VBOs::requestColor(color, n);
}

bool Asteroid::collisioned(Drawable* other) {
	if(instanceof<Laser>(other)) {
		if(n > 3) {
			--n;
			setVertices(n);
			return false;
		} else {
			// Boutta be removed. Should drop?
			if(type != Type::REGULAR) {
				// Indeed.
				Objects::cidrawablesp.alloc(new Drop(x, y, inertia.vy, type-1));
			}

			return true;
		}
	}

	return false;
}
