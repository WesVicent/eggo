/**
	Created by: Wes Ferreira 2021-05-20
*/

#pragma once
#ifndef WINDOW_H
#define WINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Window {
protected:
	Window(int width, int height, const char* title);

	void bindKeyCallBack(GLFWkeyfun cbfun);

	GLFWwindow* context;

public:
	// Virtual destructor to compiler automagically call base destructor on child destructior.
	virtual ~Window();

private:

};

#endif // !WINDOW_H

