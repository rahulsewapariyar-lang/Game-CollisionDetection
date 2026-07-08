#pragma once
#include "Mesh.h"
#include<glad/gl.h>

void Clear(
	float r,
	float g,
	float b,
	float a
);
void Render(
	const Mesh& mesh,
	GLuint shaderProgram
);