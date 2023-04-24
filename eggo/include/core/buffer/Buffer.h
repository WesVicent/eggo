/**
	Created by: Wes Ferreira 2021-05-26
*/

#pragma once

#ifndef BUFFER_H
#define BUFFER_H

#include <GL/glew.h>

#include <functional>

#include "util/Utils.h"

class Buffer {
public:
	void update(BufferData vertices);

	Buffer(BufferData vertices, const std::function<void()>& whenBond);
	Buffer(const std::function<void()>& whenBond);

	// Virtual destructor to compiler automagically call base destructor on child destructior.
	~Buffer();

private:
	const size_t BUFFER_CAPACITY = sizeof(VertexData) * 12;
	unsigned int id;

};

#endif // !BUFFER_H

