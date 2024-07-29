#pragma once

#ifndef PROG_SHADER
#define PROG_SHADER

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <GL/glew.h>

class ProgramShader
{
public:
	unsigned int id = 0;

	void attatch(unsigned int shaderId);
	void link();
	void use();
	void setUniformMat4(const char* name, glm::mat4 val);
	ProgramShader();
	~ProgramShader();

private:
	int type;

};

#endif // PROG_SHADER