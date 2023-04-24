/**
	Created by: Wes Ferreira 2019-12-28
*/

#pragma once

#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <string>
#include <sstream>
#include <filesystem>
#include <fstream>

#include "util/Utils.h"

namespace File {
	class Handler {
	public:
		static const char* read(std::string fileName);

	private:

	};
}

#endif // !FILE_H
