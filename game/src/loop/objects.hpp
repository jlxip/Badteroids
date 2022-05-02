#ifndef OBJECTS_HPP
#define OBJECTS_HPP

#include <basics/Drawable/Drawable.hpp>
#include <memory>
#include <algorithm>

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
				objs = (Drawable*)malloc(2*sizeof(T));
				lookup = (ObjID*)malloc(2*sizeof(ObjID));
				size = 2;
			}

			++last;
			if(last >= size) {
				objs = (Drawable*)realloc(objs, sizeof(T)*2*size);
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

		inline T& get(ObjID id) { return objs[id]; }


		// Very simple iterator
		typedef const T* const_iterator;
		inline const_iterator begin() const { return objs; }
		inline const_iterator end() const { return &objs[last + 1]; } // Not size!
	};

	extern Array<Drawable> drawables;
};

#endif
