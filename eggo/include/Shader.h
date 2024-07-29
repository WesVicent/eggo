#pragma once

#ifndef SHADER
#define SHADER

#include<iostream>
#include <GL/glew.h>

class Shader
{
public:
	unsigned int id;

	void compile();
	Shader(int type, const char* source);
	~Shader();

private:
	int type;

};

#endif // SHADER