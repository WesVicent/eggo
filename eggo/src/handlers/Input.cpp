#include "handlers/Input.h"

void Input::Handler::intercept(int &key, int &action, bool (&pool)[349]) {
	int GLFW_RELEASE = 0; int GLFW_PRESS = 1; int GLFW_REPEAT = 2;

	if (action == GLFW_PRESS || action == GLFW_REPEAT)
	{
		pool[key] = true;
	}

	if (action == GLFW_RELEASE)
	{
		pool[key] = false;
	}
}
