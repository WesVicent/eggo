#version 450

layout (location = 0) in vec3 position;
layout (location = 1) in vec4 color;

layout (location = 2) uniform mat4 movement;


layout (location = 6) out vec4 sharedColor;

void main() {
	gl_Position = movement * vec4(position, 1.0f);

	sharedColor = color;
}
