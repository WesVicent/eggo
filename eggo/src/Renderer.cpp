#include "Renderer.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>

const char* Renderer::VERTEX_SHADER_SOURCE = "   \n\
#version 330 core	                             \n\
layout (location = 0) in vec3 aPos;			     \n\
layout (location = 1) in vec3 aColor;		     \n\
layout (location = 2) in float aId;			     \n\
uniform mat4 u_transform;					     \n\
											     \n\
out vec3 ourColor;							     \n\
void main() {								     \n\
	vec4 position = vec4(aPos, 1.0);		     \n\
	vec3 color = aColor;					     \n\
											     \n\
	if(aId == 1){							     \n\
		position = u_transform * position;	     \n\
	}										     \n\
											     \n\
    gl_Position = position;					     \n\
    ourColor = color;						     \n\
}";

const char* Renderer::FRAGMENT_SHADER_SOURCE = " \n\
#version 330 core                                \n\
in vec3 ourColor;                                \n\
out vec4 FragColor;                              \n\
void main() {                                    \n\
    FragColor = vec4(ourColor, 1.0f);            \n\
}";

Renderer::Renderer() {
	Shader vShader(GL_VERTEX_SHADER, VERTEX_SHADER_SOURCE);
	Shader fShader(GL_FRAGMENT_SHADER, FRAGMENT_SHADER_SOURCE);

	vShader.compile();
	fShader.compile();

	program = std::make_unique<ProgramShader>();
	program->attatch(vShader.id);
	program->attatch(fShader.id);
	program->link();

	// Delete shaders (optional)
	glDeleteShader(vShader.id);
	glDeleteShader(fShader.id);

	vao = std::make_unique<Vao>();

	dataBatcher = std::make_unique<DataBatcher>();

}

void Renderer::add(BatchData data) {
	size_t indexSize = this->dataBatcher->indices.size();

	//if (indexSize >= this->dataBatcher->MAX_QUAD_IN_BATCH * 6) {
	//	this->sendDataToGPU();

	//	// Begin
	//	this->dataBatcher->dataPoint = this->dataBatcher->data;
	//	this->dataBatcher->indices = {};
	//}

	this->dataBatcher->add(data);
}

void Renderer::sendDataToGPU() {
	// vbo.bind(); TODO:
	glBindBuffer(GL_ARRAY_BUFFER, 1);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(VertexData) * (this->dataBatcher->dataPoint - this->dataBatcher->data), this->dataBatcher->data);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// ebo.bind(); TODO:
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 2);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * this->dataBatcher->indices.size(), &this->dataBatcher->indices[0], GL_STATIC_DRAW);

	this->vao->bind();
	glDrawElements(GL_TRIANGLES, this->dataBatcher->indices.size(), GL_UNSIGNED_INT, nullptr);
}

Renderer::~Renderer() {
}

