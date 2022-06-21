#ifndef BADTEROIDS_CONFIG_HPP
#define BADTEROIDS_CONFIG_HPP

#include <common.hpp>

class Config {
private:
	static constexpr const char* configFile = "config.dat";

	struct {
		bool vsync = true;
		size_t msaaxn = 4;
		bool fps = false;
	} data;

	void refresh();

public:
	void load(bool doRefresh=true);
	void save(bool doRefresh=true);

	inline bool isVSync() const { return data.vsync; }
	inline void setVSync(bool v) { data.vsync = v; save(); }

	inline size_t getMSAAxn() const { return data.msaaxn; }
	inline size_t getTrueMSAAxn() const {
		// Unmarshalling
		size_t ret = getMSAAxn();
		if(ret == 0)
			return ret;
		return 1 << ret;
	}
	inline void setMSAAxn(size_t v) { data.msaaxn = v; save(); }

	inline bool getFPS() const { return data.fps; }
	inline void setFPS(bool v) { data.fps = v; save(); }
};

#endif
