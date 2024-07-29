#include "Polygon.h"

void Polygon::createQuad(VertexData buffer[4], float x, float y, glm::vec3 color, float id) {
	float size = 0.3f;

	buffer[0] = { glm::vec3 { x, y, 0.0f },               color, id };
	buffer[1] = { glm::vec3 { x + size, y, 0.0f },        color, id };
	buffer[2] = { glm::vec3 { x + size, y + size, 0.0f }, color, id };
	buffer[3] = { glm::vec3 { x, y + size, 0.0f },        color, id };
}