/**
	Created by: Wes Ferreira 2021-05-20
*/

#pragma once
#ifndef WINDOW_CONFIG_H
#define WINDOW_CONFIG_H

#include "util/namespaces/MainWindow.h"
#include "util/namespaces/Input.h"
#include "handlers/Input.h"

class GLFWwindow;

class MainWindowSpecs {
public:
	static const int WIDTH = 800;
	static const int HEIGHT = 800;
	static const char* TITLE;

	static bool keypool[349];
	static MainWindow::EnabledKeys enabledKeys;

protected:
	static void KEY_CALLBACK(GLFWwindow* window, int key, int scancoe, int action, int mode);
};

#endif // !WINDOW_CONFIG_H

