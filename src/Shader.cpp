#include "../include/Shader.h"
#include<iostream>

GLuint CompileShader(
	GLenum type,
	const char* source
) {
	GLuint shader = glCreateShader(type);
	glShaderSource(
		shader,
		1,
		&source,
		nullptr
	);
	glCompileShader(shader);

	GLint success;
	char infoLog[512];

	glGetShaderiv(
		shader,
		GL_COMPILE_STATUS,
		&success
		);
	if (!success) {
		glGetShaderInfoLog(
			shader,
			512,
			nullptr,
			infoLog
		);

		std::cout << infoLog << '\n';

		glDeleteShader(shader);
		return 0;
	}
	return shader;
}

GLuint CreateShaderProgram(
	const char* vertexSource,
	const char* fragmentSource
) {
	GLuint vertexShader = CompileShader(GL_VERTEX_SHADER, vertexSource);
	GLuint fragmentShader = CompileShader(GL_FRAGMENT_SHADER, fragmentSource);

	if (!vertexShader || !fragmentShader)
	{
		return 0;
	}

	GLuint program = glCreateProgram();
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);
	glLinkProgram(program);

	GLint success;
	char infoLog[512];

	glGetProgramiv(
		program,
		GL_LINK_STATUS,
		&success
	);

	if (!success)
	{
		glGetProgramInfoLog(
			program,
			512,
			nullptr,
			infoLog
		);

		std::cout << infoLog << '\n';

		glDeleteProgram(program);
		program = 0;
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	return program;


}