#version 450 core

layout (location = 6) in vec4 sharedColor;
layout (location = 0) out vec4 color;

void main() {
	color = sharedColor;
	
}
