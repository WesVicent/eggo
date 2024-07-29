#include "DataBatcher.h"

void DataBatcher::add(BatchData batchData)
{
	memcpy(dataPoint, batchData.data, sizeof(VertexData) * 4);
	dataPoint = dataPoint + 4;

	unsigned int dataSize = dataPoint - data;

	if (indices.size() > 0) {
		for (int i = 0; i < batchData.indices.size(); i++) {
			batchData.indices[i] = dataSize - 4 + batchData.indices[i];
		}
	}

	this->indices.insert(this->indices.end(), batchData.indices.begin(), batchData.indices.end());
}

void DataBatcher::init() {
	data = new VertexData[100];
	dataPoint = data;
}

DataBatcher::DataBatcher() {
	init();
}

DataBatcher::~DataBatcher() {}