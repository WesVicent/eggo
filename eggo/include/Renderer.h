/**
	Created by: Wes Ferreira 2021-05-24
*/

#pragma once
#ifndef RENDERER_H
#define RENDERER_H

#include <memory>
#include <vector>

#include "util/Utils.h"
#include "window/MainWindowSpecs.h"

#include "Shader.h"
#include "ProgramShader.h"
#include "VAO.h"
#include "Buffer.h"

	class Renderer {
	public:
		std::unique_ptr<Vao> vao;
		std::unique_ptr<ProgramShader> program;

		Renderer();
		~Renderer();

	private:
		static const char* VERTEX_SHADER_SOURCE;
		static const char* FRAGMENT_SHADER_SOURCE;
	};

#endif // !RENDERER_H

