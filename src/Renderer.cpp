#include "../include/Renderer.h"
#include<iostream>

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
	GLuint shaderProgram,
	const Transform& transform
) {
	glUseProgram(shaderProgram);
	GLint scaleLocation =
		glGetUniformLocation(
			shaderProgram,
			"uScale"
		);

	GLint offsetLocation =  //GPU uOffset lives in drawer #uScale lives in drawer #1
		glGetUniformLocation(
			shaderProgram,
			"uOffset"
		);
	glUniform2f(
		scaleLocation,
		transform.scale.x,
		transform.scale.y
		//(1,1) here means maintain the original size
	);
	glUniform2f(
		offsetLocation,
		transform.position.x,
		transform.position.y
		);
	glBindVertexArray(mesh.VAO);
	glDrawArrays(
		mesh.drawMode,
		0, 
		mesh.vertexCount);
	glBindVertexArray(0);
}
