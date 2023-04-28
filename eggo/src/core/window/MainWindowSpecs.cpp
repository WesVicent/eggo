#include "core/window/MainWindowSpecs.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

// STATIC INIT
const char* MainWindowSpecs::TITLE = "WesFerreira OpenGL";
MainWindow::EnabledKeys MainWindowSpecs::enabledKeys = MainWindow::EnabledKeys();
bool MainWindowSpecs::keypool[349] = {};
//////////////

void MainWindowSpecs::KEY_CALLBACK(GLFWwindow* window, int key, int scancoe, int action, int mode) {
	Input::Handler::intercept(key, action, MainWindowSpecs::keypool);

	MainWindowSpecs::enabledKeys.right = MainWindowSpecs::keypool[Input::KEY::RIGHT];
	MainWindowSpecs::enabledKeys.left = MainWindowSpecs::keypool[Input::KEY::LEFT];
	MainWindowSpecs::enabledKeys.up = MainWindowSpecs::keypool[Input::KEY::UP];
	MainWindowSpecs::enabledKeys.down = MainWindowSpecs::keypool[Input::KEY::DOWN];

	MainWindowSpecs::enabledKeys.d = MainWindowSpecs::keypool[Input::KEY::D];
	MainWindowSpecs::enabledKeys.a = MainWindowSpecs::keypool[Input::KEY::A];
	MainWindowSpecs::enabledKeys.w = MainWindowSpecs::keypool[Input::KEY::W];
	MainWindowSpecs::enabledKeys.s = MainWindowSpecs::keypool[Input::KEY::S];

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
}
