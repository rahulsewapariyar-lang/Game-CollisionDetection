#pragma once
#include <glad/gl.h>

GLuint CompileShader( //for function reuse we are creating a function that will compile the shader and return the shader ID for vertex,fragment,geometry shaders as all are compiled in the same way and identical
	GLenum type,
	const char* source
);

GLuint CreateShaderProgram(
	const char* vertexSource,
	const char* fragmentSource
);