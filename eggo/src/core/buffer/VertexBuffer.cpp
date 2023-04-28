#include "core/buffer/VertexBuffer.h"

#include <GL/glew.h>

void VertexBuffer::update(BufferData vertices, BufferData indices) {
	unsigned int* data = (unsigned int*) indices.ref;

	glBindVertexArray(this->id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->indiceBufferId);
	glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, sizeof(unsigned int) * indices.size, data);
	glBindVertexArray(0);

	buffer->update(vertices);
}

// Static buffer
VertexBuffer::VertexBuffer(BufferData indices, BufferData vertices, const std::function<void()>& whenBond) {
	buffer = std::make_unique<Buffer>(vertices, [&]() {
		glGenVertexArrays(1, &this->id);
		glBindVertexArray(this->id);

		whenBond();

		glGenBuffers(1, &this->indiceBufferId);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->indiceBufferId);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indices.size, (unsigned int*) indices.ref, GL_STATIC_DRAW);

		glBindVertexArray(0); // Unbinding VAO
	});
}

// Dynamic buffer
VertexBuffer::VertexBuffer(const std::function<void()>& whenBond) {
	buffer = std::make_unique<Buffer>([&]() {
		glGenVertexArrays(1, &this->id);
		glBindVertexArray(this->id);

		whenBond();

		glGenBuffers(1, &this->indiceBufferId);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->indiceBufferId);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, INDEX_BUFFER_CAPACITY, nullptr, GL_DYNAMIC_DRAW);

		glBindVertexArray(0); // Unbinding VAO
	});
}

VertexBuffer::~VertexBuffer() {
	glDeleteVertexArrays(1, &this->id);
	glDeleteBuffers(1, &this->indiceBufferId);
}
