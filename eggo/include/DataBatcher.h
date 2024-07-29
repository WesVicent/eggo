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

	void add(BatchData batchData);

	DataBatcher();
	~DataBatcher();

private:
	void init();
};

#endif // BATCH_NEW