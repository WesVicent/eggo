#pragma once

#ifndef GLOBAL
#define GLOBAL

std::string BASE_PATH = "./";

namespace Path {
	std::string shaders; 
	std::string textures;
};

class Global {
public: static void init();
};

void Global::init() {
	#ifdef BUILD_TYPE_VSDEBUG
		 BASE_PATH = "../";
	#endif

	#ifdef BUILD_TYPE_CMDEBUG
		BASE_PATH = "../../";
	#endif

	Path::shaders = std::filesystem::path(BASE_PATH + "resource/shaders/").string();
	Path::textures = std::filesystem::path(BASE_PATH + "resource/textures/").string();
}

#endif // !GLOBAL
