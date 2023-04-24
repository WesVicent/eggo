#pragma once

#ifndef GLOBAL
#define GLOBAL

#include <string>
#include <filesystem>

namespace Path {
	inline std::string shaders;
	inline std::string textures;
};

class Global {
public: 
	static void init();
	inline static std::string BASE_PATH = "./";
};

#endif // !GLOBAL
