#pragma once

#ifndef MATH_H
#define MATH_H

namespace math {
	struct vec3 {
		float x; 
		float y;
		float z;
	};

	struct vec4 {
		float x;
		float y;
		float z;
		float a;
	};

	struct mat4 {
		vec4 a;
		vec4 b;
		vec4 c;
		vec4 d;

		// Identity matrix constructor
		mat4(float n) {
			a = {n, 0, 0, 0};
			b = {0, n, 0, 0};
			c = {0, 0, n, 0};
			d = {0, 0, 0, n};
		}

		mat4(vec4 a, vec4 b, vec4 c, vec4 d) {
			this->a = a;
			this->b = b;
			this->c = c;
			this->d = d;
		}
	};
}
#endif // !MATH_H

