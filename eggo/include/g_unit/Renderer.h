/**
	Created by: Wes Ferreira 2021-05-24
*/

#pragma once
#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <memory>
#include <vector>
#include <glm/gtc/matrix_transform.hpp>

#include "util/Utils.h"
#include "util/namespaces/MainWindow.h"
#include "core/window/MainWindowSpecs.h"
#include "g_unit/Batch.h"
#include "g_unit/Controllable.h"

namespace Renderer {

	class Entity {
	public:
		static std::unique_ptr<Renderer::Entity> init();

		void add(std::shared_ptr<G::Batch> batch);
		void addUnit(std::shared_ptr<G::Controllable> unit);
		void fillBuffer();
		void draw();
		bool callUpdate();
		void updatePositions();

		Entity();

	private:
		const float cameraVelocity = 0.0002f;

		bool update = false;
		std::vector<std::shared_ptr<G::Batch>> batches;
		std::vector<std::shared_ptr<G::Controllable>> unities;

		void allowCameraMovements(MainWindow::EnabledKeys key);
		Coordinates calculateMovements(MainWindow::EnabledKeys key);
	};
}
#endif // !RENDERER_H

