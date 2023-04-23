/**
	created by: Wes Ferreira 2021-05-27
*/

#pragma once
#ifndef PRIMITIVE_H
#define PRIMITIVE_H

namespace G {

	class Primitive {
	protected:

	public:
		static ShapeData createSqr(float x, float y);
		static ShapeData createSqr(float x, float y, std::vector<glm::vec4> gradient);

		virtual ~Primitive() { }; //TODO: (Need?)

	private:
	};

	ShapeData Primitive::createSqr(float x, float y) {
		std::vector<glm::vec4> defaultColor { glm::vec4 { 0.141f, 0.913f, 0.941f, 1.0f } };
		return createSqr(x, y, defaultColor);
	}
	
	ShapeData Primitive::createSqr(float x, float y, std::vector<glm::vec4> gradient) {
		VertexData v0, v1, v2, v3;
		float size = 0.05f;

		v0.position = glm::vec3 { x, y, 0.0f };
		v1.position = glm::vec3 { x + size, y, 0.0f };
		v2.position = glm::vec3 { x + size, y + size, 0.0f };
		v3.position = glm::vec3 { x, y + size, 0.0f };

		if(gradient.size() == 4) {
			v0.color = glm::vec4 { gradient[0] };
			v1.color = glm::vec4 { gradient[1] };
			v2.color = glm::vec4 { gradient[2] };
			v3.color = glm::vec4 { gradient[3] };
		} else {
			v0.color = glm::vec4 { gradient[0] };
			v1.color = glm::vec4 { gradient[0] };
			v2.color = glm::vec4 { gradient[0] };
			v3.color = glm::vec4 { gradient[0] };
		}

		return rect(v0, v1, v2, v3);
	}
}

#endif // !PRIMITIVE_H

