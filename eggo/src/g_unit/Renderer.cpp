#include "g_unit/Renderer.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>

void Renderer::Entity::allowCameraMovements(MainWindow::EnabledKeys key)
{
	bool canMove = key.d || key.a || key.w || key.s;

	if(canMove) {
		Coordinates calculated = calculateMovements(key);

		// Shaders that has uniforms with same names, even in another shader program, share these uniforms among themselves inside GPU.
		// So here, "batches[0]" because I'm changing a common uniform across all shaders, so doesn't matter which batch use to do.
		batches[0]->cameraPosition = glm::translate(batches[0]->cameraPosition, glm::vec3(calculated.x, calculated.y, 0.0f));
		batches[0]->updateUniforms(batches[0]->cameraPosition);
	}
}

Coordinates Renderer::Entity::calculateMovements(MainWindow::EnabledKeys key) {
	float x = 0.0f;
	float y = 0.0f;

	if(key.a) {
		if(key.s) {
			x = cameraVelocity;
			y = cameraVelocity;
		} else if(key.w) {
			x = cameraVelocity;
			y = cameraVelocity / -2;
		} else {
			x = cameraVelocity;
			y = 0.0f;
		}
	} else if(key.d) {
		if(key.s) {
			x = cameraVelocity * -1;
			y = cameraVelocity / 2;
		} else if(key.w) {
			x = cameraVelocity * -1;
			y = cameraVelocity / -2;
		} else {
			x = cameraVelocity * -1;
			y = 0.0f;
		}
	} else if(key.s) {
		x = 0.0f;
		y = cameraVelocity;
	} else if(key.w) {
		x = 0.0f;
		y = cameraVelocity * -1;
	}

	return Coordinates { x, y };
}

void Renderer::Entity::addUnit(std::shared_ptr<G::Controllable> unit) {
	unities.push_back(unit);
	update = true;
}

void Renderer::Entity::updatePositions() {
	allowCameraMovements(MainWindowSpecs::enabledKeys);

	for(int i = 0; i < unities.size(); i++) {
		unities[i]->allowMovements(MainWindowSpecs::enabledKeys);
	}
}

void Renderer::Entity::add(std::shared_ptr<G::Batch> batch) {
	batches.push_back(batch);
	update = true;
}

bool Renderer::Entity::callUpdate() {
	return update;
}

void Renderer::Entity::draw() {
	for(int i = 0; i < batches.size(); i++) {
		if(!batches[i]->isDynamic) {
			glBindBuffer(GL_ARRAY_BUFFER, batches[i]->buffer->id);
			glBufferData(GL_ARRAY_BUFFER, sizeof(batches[i]->VERTICES), batches[i]->VERTICES, GL_STATIC_DRAW);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}


		glBindVertexArray(batches[i]->buffer->id);
		glDrawElements(GL_TRIANGLES, sizeof(unsigned int) * batches[i]->INDICES.size(), GL_UNSIGNED_INT, nullptr);
		glBindVertexArray(0);
	}
}

std::unique_ptr<Renderer::Entity> Renderer::Entity::init() {
	return std::make_unique<Renderer::Entity>();
}

Renderer::Entity::Entity() { }

