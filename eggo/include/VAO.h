#pragma once

#ifndef VAO
#define VAO

#include <GL/glew.h>

class Vao
{
public:
	unsigned int id = 0;

	void bind();
	void unbind();

	Vao();
	~Vao();

private:

};

#endif // VAO