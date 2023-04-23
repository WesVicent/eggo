#version 330 core

in vec4 sharedColor;

out vec4 color;

void main() {
	color = sharedColor;
}
