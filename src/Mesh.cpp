#include "../include/Mesh.h"

Mesh CreateMesh(
	const float* vertices,
	size_t sizeInBytes,
	GLint componentsPerVertex
) {
	Mesh mesh{};

	glGenVertexArrays(1, &mesh.VAO);
	glGenBuffers(1, &mesh.VBO);

	glBindVertexArray(mesh.VAO);

	glBindBuffer(GL_ARRAY_BUFFER,
		mesh.VBO);

	glBufferData(
		GL_ARRAY_BUFFER,
		sizeInBytes,
		vertices,
		GL_STATIC_DRAW
	);

	glVertexAttribPointer(
		0,
		componentsPerVertex,
		GL_FLOAT,
		GL_FALSE,
		componentsPerVertex * sizeof(float),
		(void*)0
	);

	glEnableVertexAttribArray(0);

	mesh.vertexCount = static_cast<GLsizei>(sizeInBytes / (componentsPerVertex * sizeof(float))); //this calculates the number of vertices based on the size of the vertex data and the number of components per vertex

	glBindBuffer(GL_ARRAY_BUFFER, 0); //this unbinds the VBO from the GL_ARRAY_BUFFER target, which is a good practice to avoid accidental modifications to the buffer data 
	glBindVertexArray(0);

	return mesh;
}
void DestroyMesh(Mesh& mesh)
{
	glDeleteBuffers(
		1,
		&mesh.VBO
	);

	glDeleteVertexArrays(
		1,
		&mesh.VAO
	);

	mesh = {};
}