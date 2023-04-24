#include "core/window/Window.h"

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