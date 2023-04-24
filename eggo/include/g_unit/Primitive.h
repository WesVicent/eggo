/**
	created by: Wes Ferreira 2021-05-27
*/

#pragma once
#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include <vector>

#include "util/Utils.h"

namespace G {
	class Primitive {
	protected:

	public:
		static ShapeData createSqr(float x, float y);
		static ShapeData createSqr(float x, float y, std::vector<glm::vec4> gradient);

		virtual ~Primitive() { }; //TODO: (Need?)

	private:
	};
}

#endif // !PRIMITIVE_H

