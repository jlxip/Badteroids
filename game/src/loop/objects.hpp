#ifndef OBJECTS_HPP
#define OBJECTS_HPP

#include <memory>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

#include <basics/Drawable/Drawable.hpp>

typedef size_t ObjID; // Public ObjID (constant)

// Here are defined all containers for all objects that will commonly be iterated
// Custom std::vector implementation is given

namespace Objects {
	extern ObjID monotonic;

	template<typename T> class Array {
	private:
		typedef size_t IObjID; // Internal ObjID (swappable)

		std::vector<T> objs; // Index is IObjID
		std::unordered_map<ObjID, IObjID> lookup;
		std::unordered_set<ObjID> marked;

	public:
		ObjID alloc(T&& obj) {
			objs.push_back(obj);
			ObjID ret = monotonic++;
			lookup[ret] = objs.size()-1;
			return ret;
		}

	private:
		// Internal -> Public
		inline ObjID _convert(IObjID internal) {
			for(auto const& x : lookup)
				if(x.second == internal)
					return x.first;
			return ~0;
		}

		inline void _free(IObjID id) {
			lookup.erase(_convert(id));

			if(id != objs.size()-1) {
				std::swap(objs[id], objs[objs.size()-1]);
				lookup[_convert(objs.size()-1)] = id;
			}

			objs.pop_back();
		}

	public:
		inline T& get(ObjID id) { return objs[lookup[id]]; }
		inline T& operator[](ObjID id) { return get(id); }


		// Very simple iterator
		typedef typename std::vector<T>::iterator iterator;
		inline iterator begin() { return objs.begin(); }
		inline iterator end() { return objs.end(); }
		inline ObjID getID(iterator it) { return _convert(it - begin()); }
		inline void free(ObjID id) { _free(lookup[id]); }

		inline void markFree(iterator it) { marked.insert(it - begin()); }
		inline void flushFree() {
			for(auto const& x : marked)
				_free(x);
			marked.clear();
		}

		inline bool freed(ObjID id) { return lookup.find(id) == lookup.end(); }

		inline void clear() {
			objs.clear();
			lookup.clear();
		}
	};

	extern Array<Drawable> drawables;
	extern Array<Drawable> idrawables;
	extern Array<Drawable*> cidrawablesp;
};

#endif
