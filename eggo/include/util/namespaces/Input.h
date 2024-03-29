#pragma once
#ifndef NS_INPUT_H
#define NS_INPUT_H

#define GLFW_KEY_RIGHT              262
#define GLFW_KEY_LEFT               263
#define GLFW_KEY_DOWN               264
#define GLFW_KEY_UP                 265

#define GLFW_KEY_W                  87
#define GLFW_KEY_S                  83
#define GLFW_KEY_A                  65
#define GLFW_KEY_D                  68

namespace Input {
	struct KEY {
		// Player control
		static const int UP = GLFW_KEY_UP;
		static const int DOWN = GLFW_KEY_DOWN;
		static const int RIGHT = GLFW_KEY_RIGHT;
		static const int LEFT = GLFW_KEY_LEFT;

		// Camera control
		static const int W = GLFW_KEY_W;
		static const int S = GLFW_KEY_S;
		static const int D = GLFW_KEY_D;
		static const int A = GLFW_KEY_A;
	};
}

#endif // !NS_INPUT_H