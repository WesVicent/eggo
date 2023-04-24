#include "core/buffer/Buffer.h"

void Buffer::update(BufferData vertices) {
	glBindBuffer(GL_ARRAY_BUFFER, this->id);
	glBufferSubData(GL_ARRAY_BUFFER, 0, vertices.size, (VertexData*) vertices.ref);
	glBindBuffer(GL_ARRAY_BUFFER, 0); // Unbinding buffer
}

// Static buffer
Buffer::Buffer(BufferData vertices, const std::function<void()>& whenBond) {
	glGenBuffers(1, &this->id);
	glBindBuffer(GL_ARRAY_BUFFER, this->id);

	glBufferData(GL_ARRAY_BUFFER, vertices.size, (VertexData*) vertices.ref, GL_STATIC_DRAW);

	whenBond();

	glBindBuffer(GL_ARRAY_BUFFER, 0); // Unbinding buffer
}

// Dynamic buffer
Buffer::Buffer(const std::function<void()>& whenBond) {
	glGenBuffers(1, &this->id);
	glBindBuffer(GL_ARRAY_BUFFER, this->id);

	glBufferData(GL_ARRAY_BUFFER, BUFFER_CAPACITY, nullptr, GL_DYNAMIC_DRAW);

	whenBond();

	glBindBuffer(GL_ARRAY_BUFFER, 0); // Unbinding buffer
}

Buffer::~Buffer() {
	glDeleteBuffers(1, &this->id);
}
