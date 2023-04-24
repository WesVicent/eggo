#include "util/Utils.h"

// Handmade "strcpy" by Paker
const char* Utils::strclone(const char* src) {
	int size = strlen(src) + 1;
	char* dest = (char*) malloc(sizeof(char) * size);

	if(dest != 0) {
		memcpy(dest, src, size);
	}
	return dest;
}

ShapeData Utils::rect(VertexData v0, VertexData v1, VertexData v2, VertexData v3) {
	std::vector<VertexData> vertices{ v0, v1, v2, v3 };
	std::vector<unsigned int> indices{ 0, 1, 2, 2, 3, 0 };

	return { vertices, indices };
};
