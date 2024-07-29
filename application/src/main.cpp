#include "eggo.h"

// Example program
#include <iostream>
#include <string>

int main() {
	Application* app = Application::getInstance();

	DataBatcher batch = DataBatcher();

	float x = 0.0f;
	float y = 0.0f;
	float size = 0.3f;

	glm::vec3 COLOR_RED = glm::vec3(1.0f, 0.450f, 0.450f);
	glm::vec3 COLOR_GRE = glm::vec3(0.450f, 1.0f, 0.450f);
	glm::vec3 COLOR_BLU = glm::vec3(0.357f, 0.612f, 1.0f);

	VertexData data[4];
	std::vector<unsigned int> indices = { 0, 1, 2, 2, 3, 0 };

	x = -0.3f;
	y = 0.0f;

	Polygon::createQuad(data, x, y, COLOR_RED, 0.0f);
	batch.add({ data, indices });

	x = -0.15f;
	y = -0.15f;

	Polygon::createQuad(data, x, y, COLOR_GRE, 1.0f);
	batch.add({ data, indices });

	x = 0.0f;
	y = -0.3f;

	Polygon::createQuad(data, x, y, COLOR_BLU, 0.0f);
	batch.add({data, indices});

	BufferNew vbo(GL_ARRAY_BUFFER);
	BufferNew ebo(GL_ELEMENT_ARRAY_BUFFER);

	app->mainWindow->renderer->vao->bind();

	vbo.bind();
	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexData) * (batch.dataPoint - batch.data), (VertexData*) &batch.data[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void*)0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void*)(sizeof(glm::vec3)));

	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 1, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void*)(2 * sizeof(glm::vec3)));

	vbo.unbind();

	ebo.bind();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * batch.indices.size(), (unsigned int*)&batch.indices[0], GL_STATIC_DRAW);

	app->mainWindow->renderer->vao->unbind();
	
	/////////////////////////////////////////////////////////
	////////////////////    MAIN LOOP    ////////////////////
	/////////////////////////////////////////////////////////
	app->mainLoop = (const std::function<void()>) [app, batch]() {
		float xPos = 0.0f;
		float velocity = 0.0002f;
		bool isBouncingBack = false;

		while (!glfwWindowShouldClose(app->mainWindow->context)) {
			// Clear screen
			glClearColor(0.150f, 0.150f, 0.150f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			app->mainWindow->renderer->program->use();
			app->mainWindow->renderer->program->setUniformMat4("u_transform", glm::translate(glm::mat4(1.0f), glm::vec3(xPos, 0.0f, 0.0f)));

			if (isBouncingBack) {
				xPos -= velocity;
			}
			else
			{
				xPos += velocity;
			}

			if (xPos > 0.85f) {
				isBouncingBack = true;
			}

			if (xPos < -0.85f) {
				isBouncingBack = false;
			}

			app->mainWindow->renderer->vao->bind();

			glDrawElements(GL_TRIANGLES, batch.indices.size(), GL_UNSIGNED_INT, nullptr);

			// Swap buffers and poll events
			glfwSwapBuffers(app->mainWindow->context);
			glfwPollEvents();
		}

	};

	app->run();

	return 0;
}