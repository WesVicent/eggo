#pragma once
#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>

#include "math/math.h"


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
	math::vec3 position;
	math::vec4 color;
};


struct ShapeData {
	std::vector<VertexData> vertices;
	std::vector<unsigned int> indices;

	unsigned int size = (unsigned int) vertices.size() * sizeof(VertexData);
};

struct Utils {
	// Handmade "strcpy" by Paker
	static const char* strclone(const char* src);
	static ShapeData rect(VertexData v0, VertexData v1, VertexData v2, VertexData v3);
};

#endif // !UTILS_H
