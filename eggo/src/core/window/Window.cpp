#include "core/window/Window.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

void Window::bindKeyCallBack(GLFWkeyfun cbfun) {
	glfwSetKeyCallback(this->context, cbfun);
}

void Window::ErrorCallback(int, const char* err_str)
{
	std::cout << "GLFW Error: " << err_str << std::endl;
}

Window::Window(int width, int height, const char* title) {
	glfwSetErrorCallback(Window::ErrorCallback);
	glfwInit();

	// Setting up OpenGL
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
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