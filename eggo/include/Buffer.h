#pragma once


#ifndef BUFFER_NEW
#define BUFFER_NEW

#include <GL/glew.h>

class BufferNew
{
public:
	unsigned int id;
	int type;

	void bind();
	void unbind();
	BufferNew(int type);
	~BufferNew();

private:

};

#endif // BUFFER_NEW