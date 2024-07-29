#include "ProgramShader.h"

ProgramShader::ProgramShader()
{
	id = glCreateProgram();
}

void ProgramShader::attatch(unsigned int shaderId)
{
	glAttachShader(id, shaderId);
}

void ProgramShader::link()
{
	glLinkProgram(id);

	// Check for shader linking errors
	int success;
	char infoLog[512];
	glGetProgramiv(id, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(id, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}
}

void ProgramShader::use()
{
	glUseProgram(id);
}

void ProgramShader::setUniformMat4(const char* name, glm::mat4 val)
{
	int uniform = glGetUniformLocation(id, name);
	glUniformMatrix4fv(uniform, 1, GL_FALSE, glm::value_ptr(val));
}

ProgramShader::~ProgramShader()
{
	glDeleteProgram(id);
}