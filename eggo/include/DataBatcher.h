#pragma once

#ifndef BATCH_NEW
#define BATCH_NEW

#include <glm/glm.hpp>
#include <vector>

struct VertexData {
	glm::vec3 position;
	glm::vec3 color;
	float id;
};

struct BatchData {
	VertexData* data;
	std::vector<unsigned int> indices;
};

class DataBatcher {

public:
	VertexData* data;
	VertexData* dataPoint;
	std::vector<unsigned int> indices;

	const unsigned int MAX_QUAD_IN_BATCH   = 2;
	const unsigned int MAX_QUAD_IN_BUFFER   = 10;
	const unsigned int MAX_VERTEX_COUNT = MAX_QUAD_IN_BUFFER * 4;
	const unsigned int MAX_INDEX_COUNT  = MAX_QUAD_IN_BUFFER * 6;

	void add(BatchData batchData);
	void sendDataToGPU();

	DataBatcher();
	~DataBatcher();

private:
	void init();
};

#endif // BATCH_NEW