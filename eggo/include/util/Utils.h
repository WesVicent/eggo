#pragma once
#ifndef UTILS_H
#define UTILS_H

#include <glm/glm.hpp>
#include <vector>
#include <string>

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

struct Utils {
	// Handmade "strcpy" by Paker
	static const char* strclone(const char* src);
	static ShapeData rect(VertexData v0, VertexData v1, VertexData v2, VertexData v3);
};

#endif // !UTILS_H
