#include "handlers/File.h"

	const char* File::Handler::read(std::string fileName)
	{
		std::stringstream content;
		std::string line;
		std::ifstream file(fileName);

		if (file.is_open()) {
			while (std::getline(file, line)) {
				content << line << '\n';
			}
			file.close();
		} else {
			std::cout << std::filesystem::path() << std::endl;
			std::cout << "Unable to open file: " + fileName << std::endl;
		}

		// The c_str() function return haven't reference on another scope, to keep reference we clone it return.
		return Utils::strclone(content.str().c_str());
	}

