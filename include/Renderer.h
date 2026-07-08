#pragma once
#include "Mesh.h"
#include<glad/gl.h>
#include "../include/Transform.h"

void Clear(
	float r,
	float g,
	float b,
	float a
);
void Render(
	const Mesh& mesh,
	GLuint shaderProgram,
	const Transform& transform
);