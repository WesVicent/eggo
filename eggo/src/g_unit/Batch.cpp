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

void G::Batch::updateUniforms(math::mat4 movement) {
	// TODO: Remove this static casting. 
	glm::vec4 v0 = glm::vec4(movement.a.x, movement.a.y, movement.a.z, movement.a.a);
	glm::vec4 v1 = glm::vec4(movement.b.x, movement.b.y, movement.b.z, movement.b.a);
	glm::vec4 v2 = glm::vec4(movement.c.x, movement.c.y, movement.c.z, movement.c.a);
	glm::vec4 v3 = glm::vec4(movement.d.x, movement.d.y, movement.d.z, movement.d.a);

	glm::mat4 matrix = glm::mat4(v0, v1, v2, v3);
	glUseProgram(programShader);
	int u_movement = glGetUniformLocation(programShader, "movement");
	glUniformMatrix4fv(u_movement, 1, GL_FALSE, glm::value_ptr(matrix));
}

void G::Batch::processUniforms() {
	glUseProgram(programShader);
	int u_movement = glGetUniformLocation(programShader, "movement");

	// TODO: Remove this static casting. 
	glm::vec4 v0 = glm::vec4(cameraPosition.a.x, cameraPosition.a.y, cameraPosition.a.z, cameraPosition.a.a);
	glm::vec4 v1 = glm::vec4(cameraPosition.b.x, cameraPosition.b.y, cameraPosition.b.z, cameraPosition.b.a);
	glm::vec4 v2 = glm::vec4(cameraPosition.c.x, cameraPosition.c.y, cameraPosition.c.z, cameraPosition.c.a);
	glm::vec4 v3 = glm::vec4(cameraPosition.d.x, cameraPosition.d.y, cameraPosition.d.z, cameraPosition.d.a);

	glm::mat4 matrix = glm::mat4(v0, v1, v2, v3);

	glm::mat4 cameraP = glm::translate(matrix, glm::vec3(0.0f, 0.0f, 0.0f));

	math::vec4 mV0 = {cameraP[0].x, cameraP[0].y , cameraP[0].z , cameraP[0].w};
	math::vec4 mV1 = {cameraP[1].x, cameraP[1].y , cameraP[1].z , cameraP[1].w};
	math::vec4 mV2 = {cameraP[2].x, cameraP[2].y , cameraP[2].z , cameraP[2].w};
	math::vec4 mV3 = {cameraP[3].x, cameraP[3].y , cameraP[3].z , cameraP[3].w};

	cameraPosition = {mV0, mV1, mV2, mV3};

	glUniformMatrix4fv(u_movement, 1, GL_FALSE, glm::value_ptr(matrix));
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
