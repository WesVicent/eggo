/**
	Created by: Wes Ferreira 2021-05-20
*/

#pragma once
#ifndef WINDOW_H
#define WINDOW_H

#include "Renderer.h"

class GLFWwindow;
typedef void (*GLFWkeyfun)(GLFWwindow* window, int key, int scancode, int action, int mods);

class Window {
protected:
	static void ErrorCallback(int, const char* err_str);

	void bindKeyCallBack(GLFWkeyfun cbfun);
public:
	GLFWwindow* context;
	std::unique_ptr<Renderer> renderer;

	Window(int width, int height, const char* title);

	// Virtual destructor to compiler automagically call base destructor on child destructior.
	virtual ~Window();

private:

};

#endif // !WINDOW_H

