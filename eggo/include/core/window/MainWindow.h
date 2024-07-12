/**
	Created by: Wes Ferreira 2021-05-20
*/

#pragma once
#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <memory>

#include "core/window/Window.h"
#include "core/window/MainWindowSpecs.h"
#include "g_unit/Renderer.h"

class GLFWwindow;

namespace MainWindow {

	inline std::unique_ptr<Renderer::Entity> renderer;

	class Entity : public Window, public MainWindowSpecs {
	public:
		static GLFWwindow* init();

		Entity(int width, int height, const char* title);
		~Entity();
	};
}

#endif // !MAIN_WINDOW_H

