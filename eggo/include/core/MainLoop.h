/**
	Created by: Wes Ferreira 2021-05-20
*/

#pragma once
#ifndef MAIN_LOOP_H
#define MAIN_LOOP_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "core/window/MainWindow.h"

namespace MainLoop {
	class Entity {
	protected:

	public:
		static void init(GLFWwindow* context);
	private:

	};
}
#endif // !MAIN_LOOP_H

