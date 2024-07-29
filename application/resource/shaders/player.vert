#version 450

layout (location = 0) in vec3 position;
layout (location = 1) in vec4 color;
layout (location = 2) in mat4 modelMatrix;
layout (location = 6) uniform mat4 model;
layout (location = 10) uniform mat4 view;
layout (location = 14) uniform mat4 projection;
layout (location = 18) out vec4 sharedColor;

void main() {
	vec4 worldPos = model * vec4(position, 1.0);
	gl_Position = projection * view * worldPos;

	sharedColor = color;
}
