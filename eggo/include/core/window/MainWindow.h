/**
	Created by: Wes Ferreira 2021-05-20
*/

#pragma once
#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <memory>

#include "core/window/Window.h"
#include "core/window/MainWindowSpecs.h"
#include "g_unit/Renderer.h"

namespace MainWindow {

	inline std::unique_ptr<Renderer::Entity> renderer;

	class Entity : public Window, public MainWindowSpecs {
	protected:

	public:
		static GLFWwindow* init();

		Entity(int width, int height, const char* title);
		~Entity();
	private:

	};
}

#endif // !MAIN_WINDOW_H

