#include "handlers/Input.h"

void Input::Handler::intercept(int &key, int &action, bool (&pool)[349])
{
	if (action == GLFW_PRESS || action == GLFW_REPEAT)
	{
		pool[key] = true;
	}

	if (action == GLFW_RELEASE)
	{
		pool[key] = false;
	}
}
