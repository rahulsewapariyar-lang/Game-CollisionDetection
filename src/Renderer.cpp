#include "../include/Renderer.h"

void Clear(
	float r,
	float g,
	float b,
	float a
) {
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Render(
	const Mesh& mesh,
	GLuint shaderProgram
) {
	glUseProgram(shaderProgram);
	glBindVertexArray(mesh.VAO);
	glDrawArrays(
		GL_TRIANGLES,
		0, 
		mesh.vertexCount);
	glBindVertexArray(0);
}
