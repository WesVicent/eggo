/**
	Created by: Wes Ferreira 2021-05-21
*/

#pragma once
#ifndef BATCH_H
#define BATCH_H

#include <iostream>
#include <memory>
#include <vector>

#include "util/Utils.h"
#include "util/Global.h"
#include "core/buffer/VertexBuffer.h"
#include "handlers/File.h"

typedef unsigned int GLuint;

namespace G {
	class Batch {
	public:
		bool isDynamic = false;
		int VERTICES_COUNT = 0;
		math::mat4 cameraPosition = math::mat4(1.0);
		std::unique_ptr<VertexBuffer> buffer;
		std::vector<unsigned int> INDICES;
		VertexData VERTICES[3 * 4]; // UNIT_MAX_COUNT * VERTEX_MAX_AMOUNT
		GLuint programShader;

		void add(ShapeData unit);
		void updateUniforms(math::mat4 movement);
		void updateBuffer();

		Batch();
		Batch(ShapeData unit);

	private:
		void processShaders();
		void processUniforms();

	};
}

#endif // !BATCH_H

