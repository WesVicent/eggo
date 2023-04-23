/**
	Created by: Wes Ferreira 2021-05-20
*/

#pragma once
#ifndef MAIN_LOOP_H
#define MAIN_LOOP_H
namespace MainLoop {
	class Entity {
	protected:

	public:
		static void init(GLFWwindow* context);
	private:

	};

	void Entity::init(GLFWwindow* context) {
		while (!glfwWindowShouldClose(context)) {
			glfwPollEvents();

			glClear(GL_COLOR_BUFFER_BIT);

			if (MainWindow::renderer->callUpdate()) {
				MainWindow::renderer->updatePositions();
				MainWindow::renderer->draw();
			}

			glfwSwapBuffers(context);
		}
	}
}
#endif // !MAIN_LOOP_H

