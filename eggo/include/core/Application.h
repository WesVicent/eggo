/**
	Created by: Wes Ferreira 2021-05-21
*/

#pragma once
#ifndef APPLICATION_H
#define APPLICATION_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "core/window/MainWindow.h"
#include "core/MainLoop.h"
#include "util/Utils.h"
#include "g_unit/Batch.h"	
#include "g_unit/player/Player.h"	


class Application { // Singleton
protected:
public:
	GLFWwindow* windowContext;

	static Application* getInstance();
	~Application();

private:
	static Application* instance;
	Application();


};
#endif // !APPLICATION_H

