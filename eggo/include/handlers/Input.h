/**
	Created by: Wes Ferreira 2020-01-05
*/

#pragma once

#ifndef H_INPUT_H
#define H_INPUT_H

namespace Input {
	class Handler {
	public:
		static void intercept(int &key, int &action, bool (&pool)[349]);

	private:
	};
}

#endif // !H_INPUT_H
