#include "VAO.h"

Vao::Vao()
{
	glGenVertexArrays(1, &id);
}

Vao::~Vao()
{
	glDeleteVertexArrays(1, &id);
}

void Vao::bind()
{
	glBindVertexArray(id);
}

void Vao::unbind()
{
	glBindVertexArray(0);
}