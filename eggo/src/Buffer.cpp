#include "Buffer.h"

BufferNew::BufferNew(int type)
{
	this->type = type;
	glGenBuffers(1, &id);
}

void BufferNew::bind()
{
	glBindBuffer(type, id);
}

void BufferNew::unbind()
{
	glBindBuffer(type, 0);
}

BufferNew::~BufferNew()
{
	glDeleteBuffers(1, &id);
}