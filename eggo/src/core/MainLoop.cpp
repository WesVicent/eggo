#include "core/MainLoop.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

void MainLoop::Entity::init(GLFWwindow *context) {
	while (!glfwWindowShouldClose(context))
	{
		glfwPollEvents();

		glClear(GL_COLOR_BUFFER_BIT);

		if (MainWindow::renderer->callUpdate())
		{
			MainWindow::renderer->updatePositions();
			MainWindow::renderer->draw();
		}

		glfwSwapBuffers(context);
	}
}