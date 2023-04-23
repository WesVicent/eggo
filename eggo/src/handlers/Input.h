/**
	Created by: Wes Ferreira 2020-01-05
*/

#pragma once

#ifndef H_INPUT_H
#define H_INPUT_H

namespace Input {
	class Handler {
	public:
		static void intercept(int& key, int& action, bool (&pool)[349]);

	private:
	};

	void Handler::intercept(int& key, int& action, bool (&pool) [349]) {
		if (action == GLFW_PRESS || action == GLFW_REPEAT) {
			pool[key] = true;
		}
		
		if (action == GLFW_RELEASE) {
			pool[key] = false;
		}

	}
}

#endif // !H_INPUT_H
