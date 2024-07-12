#include "g_unit/player/Player.h"

#include <glm/gtc/matrix_transform.hpp>


Player::Player() :Player(0.0f, 0.0f) { }

Player::Player(float x, float y) {
	auto quad = G::Primitive::createSqr(0.0f + x, 0.0f + y);

	VertexData v0, v1, v2;
	float size = 0.05f;
	v0.position = math::vec3 { 0.10f, 0.0f, 0.0f };
	v1.position = math::vec3 { 0.10f + size, 0.0f, 0.0f };
	v2.position = math::vec3 { 0.10f + size / 2, size, 0.0f };

	v0.color = math::vec4 { 0.141f, 0.913f, 0.941f, 1.0f };
	v1.color = math::vec4 { 0.141f, 0.913f, 0.941f, 1.0f };
	v2.color = math::vec4 { 0.141f, 0.913f, 0.941f, 1.0f };

	ShapeData tri = { {v0, v1, v2}, {0, 1, 2} };

	batch = std::make_shared<G::Batch>();

	batch->add(quad);
	batch->add(tri);

	MainWindow::renderer->add(batch);
}

Player::~Player() {
}

void Player::allowMovements(MainWindow::EnabledKeys key) {
	checkMovementCall(key);

	if (this->canMove) {
		Coordinates calculated = calculateMovements(key);

		for(int i = 0; i < batch->VERTICES_COUNT; i++) {
			batch->VERTICES[i].position = math::vec3 {batch->VERTICES[i].position.x + calculated.x, batch->VERTICES[i].position.y + calculated.y, 1.0f};
			batch->VERTICES[i].color = math::vec4 {batch->VERTICES[i].color.x + 0.0002f, batch->VERTICES[i].color.y + 0.0002f, batch->VERTICES[i].color.z + 0.0002f, 1.0f};
		}

		// TODO: Remove this static casting. 
		glm::vec4 v0 = glm::vec4(this->movement.a.x, this->movement.a.y, this->movement.a.z, this->movement.a.a);
		glm::vec4 v1 = glm::vec4(this->movement.b.x, this->movement.b.y, this->movement.b.z, this->movement.b.a);
		glm::vec4 v2 = glm::vec4(this->movement.c.x, this->movement.c.y, this->movement.c.z, this->movement.c.a);
		glm::vec4 v3 = glm::vec4(this->movement.d.x, this->movement.d.y, this->movement.d.z, this->movement.d.a);

		glm::mat4 matrix = glm::mat4(v0, v1, v2, v3);

		glm::mat4 movement = glm::translate(matrix, glm::vec3(calculated.x, calculated.y, 0.0f));

		math::vec4 mV0 = { movement[0].x, movement[0].y , movement[0].z , movement[0].w };
		math::vec4 mV1 = { movement[1].x, movement[1].y , movement[1].z , movement[1].w };
		math::vec4 mV2 = { movement[2].x, movement[2].y , movement[2].z , movement[2].w };
		math::vec4 mV3 = { movement[3].x, movement[3].y , movement[3].z , movement[3].w };

		this->movement = { mV0, mV1, mV2, mV3 };

		batch->updateBuffer();
	}
}

void Player::checkMovementCall(MainWindow::EnabledKeys key) {
	this->canMove = key.right || key.left || key.up || key.down;
}

Coordinates Player::calculateMovements(MainWindow::EnabledKeys key) {
	float x = 0.0f;
	float y = 0.0f;

	if (key.right) {
		if (key.up) {
			x = velocity;
			y = velocity;
		} else if (key.down) {
			x = velocity;
			y = velocity / -2;
		} else {
			x = velocity;
			y = 0.0f;
		}
	} else if (key.left) {
		if (key.up) {
			x = velocity * -1;
			y = velocity / 2;
		} else if (key.down) {
			x = velocity * -1;
			y = velocity / -2;
		} else {
			x = velocity * -1;
			y = 0.0f;
		}
	} else if (key.up) {
		x = 0.0f;
		y = velocity;
	} else if (key.down) {
		x = 0.0f;
		y = velocity * -1;
	}

	return Coordinates{ x, y };
}
