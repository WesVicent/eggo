/**
	Created by: Wes Ferreira 2021-05-21
*/

#pragma once
#ifndef APPLICATION_H
#define APPLICATION_H

#include "window/Window.h"
#include "util/Global.h"
#include <functional>
#include <memory>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Polygon.h"

class GLFWwindow;

class Application { // Singleton
public:
	std::unique_ptr<Window> mainWindow;
	std::function<void()> mainLoop;

	void run() const;
	static Application* getInstance();
	~Application();

private:
	static Application* instance;
	Application();
};
#endif // !APPLICATION_H

