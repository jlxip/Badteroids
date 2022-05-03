#ifndef OBJECTS_HPP
#define OBJECTS_HPP

#include <memory>
#include <algorithm>

#include <basics/Drawable/Drawable.hpp>

typedef size_t ObjID;

// Here are defined all containers for all objects that will commonly be iterated
// Custom std::vector implementation is given

namespace Objects {
	template<typename T> class Array {
	private:
		T* objs = nullptr;
		size_t last = ~0;
		size_t size = 0;
		ObjID* lookup = nullptr; // Constant ObjID -> swappable ObjID

	public:
		ObjID alloc(T&& obj) {
			if(!size) {
				objs = (T*)malloc(2*sizeof(T));
				lookup = (ObjID*)malloc(2*sizeof(ObjID));
				size = 2;
			}

			++last;
			if(last >= size) {
				objs = (T*)realloc(objs, sizeof(T)*2*size);
				lookup = (ObjID*)realloc(lookup, sizeof(ObjID)*2*size);
				size *= 2;
			}

			objs[last] = obj;
			lookup[last] = last;
			return last;
		}

		inline void free(ObjID id) {
			std::swap(objs[id], objs[last]);
			lookup[last] = id;
			--last;
		}

		inline T& get(ObjID id) { return objs[lookup[id]]; }


		// Very simple iterator
		typedef T* iterator;
		inline iterator begin() { return objs; }
		inline iterator end() { return &objs[last + 1]; } // Not size!
	};

	extern Array<Drawable> drawables;
	extern Array<Drawable> idrawables;
};

#endif
