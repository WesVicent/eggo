/**
	Created by: Wes Ferreira 2020-01-05
*/

#pragma once
#ifndef PLAYER_H
#define PLAYER_H

class Player : public G::Controllable {
public:
	bool canMove = false;
	
	void virtual allowMovements(MainWindow::EnabledKeys key);

	Player(float x, float y);
	Player();
	~Player();

private:
	const float velocity = 0.0002f;
	
	glm::mat4 movement = glm::mat4(1.0);
	
	int u_movement;
	std::shared_ptr<G::Batch> batch;

	void checkMovementCall(MainWindow::EnabledKeys key);
	Coordinates calculateMovements(MainWindow::EnabledKeys key);
};

Player::Player() :Player(0.0f, 0.0f) { }

Player::Player(float x, float y) {
	auto quad = G::Primitive::createSqr(0.0f + x, 0.0f + y);

	VertexData v0, v1, v2;
	float size = 0.05f;
	v0.position = glm::vec3 { 0.10f, 0.0f, 0.0f };
	v1.position = glm::vec3 { 0.10f + size, 0.0f, 0.0f };
	v2.position = glm::vec3 { 0.10f + size / 2, size, 0.0f };

	v0.color = glm::vec4 { 0.141f, 0.913f, 0.941f, 1.0f };
	v1.color = glm::vec4 { 0.141f, 0.913f, 0.941f, 1.0f };
	v2.color = glm::vec4 { 0.141f, 0.913f, 0.941f, 1.0f };

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
			batch->VERTICES[i].position = glm::vec3(batch->VERTICES[i].position.x + calculated.x, batch->VERTICES[i].position.y + calculated.y, 1.0f);
		}

		this->movement = glm::translate(this->movement, glm::vec3(calculated.x, calculated.y, 0.0f));
		
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


#endif // !PLAYER_H
