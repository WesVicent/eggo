#pragma once


#ifndef BUFFER_NEW
#define BUFFER_NEW

#include <GL/glew.h>

class BufferNew
{
public:
	unsigned int id;

	void bind();
	void unbind();
	BufferNew(int type);
	~BufferNew();

private:
	int type;

};

#endif // BUFFER_NEW