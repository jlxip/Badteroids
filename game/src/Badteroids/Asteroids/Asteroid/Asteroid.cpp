#include "Asteroid.hpp"
#include <unordered_map>
#include <vector>
#include <cmath>
#include <Badteroids/Ship/Laser/Laser.hpp>

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

Asteroid::Asteroid() {
	this->mode = GL_LINES;
}

void Asteroid::setVertices(size_t n_) {
	n = n_;
	if(vertices.find(n) == vertices.end())
		generate(n);

	this->VBO_v = VBOsv[n];
	this->VBO_i = VBOsi[n];
	this->isize = n*(n-1);
}

bool Asteroid::collisioned(Drawable* other) {
	if(instanceof<Laser>(other)) {
		if(n > 3) {
			--n;
			setVertices(n);
			return false;
		} else {
			return true;
		}
	}

	return false;
}
