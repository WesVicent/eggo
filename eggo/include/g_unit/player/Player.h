/**
	Created by: Wes Ferreira 2020-01-05
*/

#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "util/namespaces/MainWindow.h"
#include "core/window/MainWindow.h"
#include "util/Utils.h"
#include "g_unit/Controllable.h"
#include "g_unit/Primitive.h"
#include "g_unit/Batch.h"


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
#endif // !PLAYER_H
