#pragma once
#ifndef UTILS_H
#define UTILS_H

struct Utils {
	// Handmade "strcpy" by Paker
	static const char* strclone(const char* src) {
		int size = strlen(src) + 1;
		char* dest = (char*) malloc(sizeof(char) * size);

		if(dest != 0) {
			memcpy(dest, src, size);
		}
		return dest;
	}
};

// USEFUL STRUCTS
struct Coordinates {
	float x;
	float y;
};

struct BufferData {
	size_t size;
	void* ref;
};

struct VertexData {
	glm::vec3 position;
	glm::vec4 color;
};

struct ShapeData {
	std::vector<VertexData> vertices;
	std::vector<unsigned int> indices;

	unsigned int size = (unsigned int) vertices.size() * sizeof(VertexData);
};

ShapeData rect(VertexData v0, VertexData v1, VertexData v2, VertexData v3) {
	std::vector<VertexData> vertices { v0, v1, v2, v3 };
	std::vector<unsigned int> indices { 0, 1, 2, 2, 3, 0 };

	return { vertices, indices};
}

/////////////////
#endif // !UTILS_H
