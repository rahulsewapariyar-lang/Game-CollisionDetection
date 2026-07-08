#include "../include/Mesh.h"
#include <vector>
#include <cmath>

constexpr float PI = 3.14159265358979323846f;

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

 Mesh CreateCircleMesh(
	float radius,
	int segments
) {
	std::vector<float> vertices;

	vertices.push_back(0.0f); //for x
	vertices.push_back(0.0f); //for y

	for (int i = 0;i <= segments;i++) {
		float angle = (2.0f * PI * i / segments);

		float x = radius * cos(angle);
		float y = radius * sin(angle);

		vertices.push_back(x);
		vertices.push_back(y);
	}
	 
	Mesh mesh = CreateMesh(
		vertices.data(),
		vertices.size() * sizeof(float),
	    2
		);
	mesh.drawMode = GL_TRIANGLE_FAN;
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