#include "util/Global.h"

#include <iostream>

void Global::init() {
	
	BASE_PATH = "../";

	Path::shaders = std::filesystem::path(BASE_PATH + "resource/shaders/").string();
	Path::textures = std::filesystem::path(BASE_PATH + "resource/textures/").string();
}
