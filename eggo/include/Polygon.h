#pragma once

#ifndef POLYGON_H
#define POLYGON_H

#include "DataBatcher.h"

class Polygon {
public:

	/*
		Add square vertices to the buffer
	*/
	static void createQuad(VertexData buffer[4], float x, float y, glm::vec3 color, float id);
};

#endif // POLYGON_H