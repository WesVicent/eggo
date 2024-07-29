#include "Shader.h"

Shader::Shader(int type, const char* source)
{
	this->type = type;
	id = glCreateShader(type);

	glShaderSource(id, 1, &source, NULL);
}

void Shader::compile()
{
	glCompileShader(id);

	// Check for shader compilation errors
	int success;
	char infoLog[512];
	glGetShaderiv(id, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(id, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
}

Shader::~Shader()
{
}