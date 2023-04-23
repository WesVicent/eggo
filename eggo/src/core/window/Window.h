/**
	Created by: Wes Ferreira 2021-05-20
*/

#pragma once
#ifndef WINDOW_H
#define WINDOW_H

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

void Window::bindKeyCallBack(GLFWkeyfun cbfun) {
	glfwSetKeyCallback(this->context, cbfun);
}

Window::Window(int width, int height, const char* title) {
	glfwInit();

	// Setting up OpenGL
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_DECORATED, GLFW_TRUE);
	///////////////////

	this->context = glfwCreateWindow(width, height, title, nullptr, nullptr);

	glfwMakeContextCurrent(context);

	glewExperimental = GL_TRUE;
	glewInit();

	glViewport(0, 0, width, height);
}

Window::~Window() {
}

#endif // !WINDOW_H

