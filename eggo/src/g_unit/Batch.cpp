#include "g_unit/Batch.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GL/glew.h>


G::Batch::Batch() {
	isDynamic = true;

	this->buffer = std::make_unique<VertexBuffer>([&]() {
	// Statements for when VertexBuffer is bonded.
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void*) 0);

		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void*) sizeof(glm::vec3));
	});

	processShaders();
	processUniforms();
}

G::Batch::Batch(ShapeData unit) {
	add(unit);

	BufferData vertices { sizeof(VERTICES), &VERTICES[0] };
	BufferData indices { INDICES.size(), &INDICES[0] };

	this->buffer = std::make_unique<VertexBuffer>(indices, vertices, [&]() {
	// Statements for when VertexBuffer is bonded.
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void*) 0);

		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void*) sizeof(glm::vec3));
	});

	processShaders();
	processUniforms();
}

void G::Batch::updateBuffer() {

	BufferData vertices { sizeof(VERTICES), &VERTICES[0] };
	BufferData indices { INDICES.size(), &INDICES[0] };

	buffer->update(vertices, indices);
}

void G::Batch::updateUniforms(glm::mat4 movement) {
	glUseProgram(programShader);
	int u_movement = glGetUniformLocation(programShader, "movement");
	glUniformMatrix4fv(u_movement, 1, GL_FALSE, glm::value_ptr(movement));
}

void G::Batch::processUniforms() {
	glUseProgram(programShader);
	int u_movement = glGetUniformLocation(programShader, "movement");

	cameraPosition = glm::translate(cameraPosition, glm::vec3(0.0f, 0.0f, 0.0f));

	glUniformMatrix4fv(u_movement, 1, GL_FALSE, glm::value_ptr(cameraPosition));
}

void G::Batch::add(ShapeData unit) {
	memcpy(VERTICES + VERTICES_COUNT, unit.vertices.data(), unit.size);

	for(int i = 0; i < unit.indices.size(); i++) {
		unit.indices.at(i) += VERTICES_COUNT;
	}
	VERTICES_COUNT += unit.vertices.size();

	// std::copy() delegates the calls to memmove() when the type is TriviallyCopyable.
	std::copy(unit.indices.begin(), unit.indices.end(), std::back_inserter(INDICES));

	if (isDynamic) updateBuffer();
}

void G::Batch::processShaders() {
	const char* vertexShaderSource = File::Handler::read(Path::shaders + "player.vert");
	const char* fragmentShaderSource = File::Handler::read(Path::shaders + "player.frag");

	GLuint vertexShader, fragmentShader;
	GLint success;

	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

	delete vertexShaderSource;
	delete fragmentShaderSource;

	// Linking shaders.
	this->programShader = glCreateProgram();
	glAttachShader(this->programShader, vertexShader);
	glAttachShader(this->programShader, fragmentShader);
	glLinkProgram(this->programShader);

	glGetProgramiv(this->programShader, GL_LINK_STATUS, &success);

	// Cleaning shaders.
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}
