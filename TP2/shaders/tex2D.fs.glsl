#version 330 core

in vec3 vFragColor;
in vec2 vFragTexture;
in vec2 vFragPosition;

out vec3 fFragColor;

void main() {
		fFragColor = vFragColor;
};