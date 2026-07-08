#pragma once
#include <glad/gl.h>

//this file simply is vertices + VBO + VAO + shader program creation that can be reused in the main.cpp file to create a rectangle VAO and return its ID for rendering
struct Mesh{
	GLuint VAO{0};
	GLuint VBO{0};
	GLsizei vertexCount{0};
};

Mesh CreateMesh(
	const float* vertices,
	size_t sizeInBytes,
	GLint componentsPerVertex
);

void DestroyMesh(Mesh& mesh);