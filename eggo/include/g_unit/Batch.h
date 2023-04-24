/**
	Created by: Wes Ferreira 2021-05-21
*/

#pragma once
#ifndef BATCH_H
#define BATCH_H

#include <GL/glew.h>

#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <memory>
#include <vector>

#include "util/Utils.h"
#include "util/Global.h"
#include "core/buffer/VertexBuffer.h"
#include "handlers/File.h"

namespace G {
	class Batch {
	public:
		bool isDynamic = false;
		int VERTICES_COUNT = 0;
		glm::mat4 cameraPosition = glm::mat4(1.0);
		std::unique_ptr<VertexBuffer> buffer;
		std::vector<unsigned int> INDICES;
		VertexData VERTICES[3 * 4]; // UNIT_MAX_COUNT * VERTEX_MAX_AMOUNT
		GLuint programShader;

		void add(ShapeData unit);
		void updateUniforms(glm::mat4 movement);
		void updateBuffer();

		Batch();
		Batch(ShapeData unit);

	private:
		void processShaders();
		void processUniforms();

	};
}

#endif // !BATCH_H

