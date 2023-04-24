/**
	Created by: Wes Ferreira 2021-05-26
*/

#pragma once

#ifndef VERTEX_BUFFER_H
#define VERTEX_BUFFER_H

#include <GL/glew.h>

#include <functional>

#include "util/Utils.h"
#include "core/buffer/Buffer.h"

class VertexBuffer {
protected:

public:
	unsigned int id;

	void update(BufferData vertices, BufferData indices);

	VertexBuffer(BufferData indices, BufferData vertices, const std::function<void()>& whenBond);
	VertexBuffer(const std::function<void()>& whenBond);
	virtual ~VertexBuffer();


private:
	unsigned int indiceBufferId;
	std::unique_ptr<Buffer> buffer;
	const size_t INDEX_BUFFER_CAPACITY = sizeof(unsigned int) * 18;
};

#endif // !VERTEX_BUFFER_H
