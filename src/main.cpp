#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include<iostream>
#include "../include/Vec2.h"
#include "../include/Rectangle.h"
#include "../include/Ball.h"
#include "../include/Update.h"
#include "../include/Collision.h"

int main() {

	if (!glfwInit())
	{
		std::cout << "Failed to initialize GLFW\n";
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(
		800,
		600,
		"Collision Detection",
		nullptr,
		nullptr
	);

	if (!window) {
		std::cout << "Failed to create GLFW window\n";
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window); //make the opengl context current so that glad can load the function pointers for the current context


	//initialize glad to load the opengl function pointers for the current context
	if (!gladLoadGL(glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD\n";
		glfwTerminate();
		return -1;
	}

	float vertices[] =
	{
		-0.5f, -0.5f,
		 0.5f, -0.5f,
		 0.0f,  0.5f
	};

	GLuint VBO; //vbo lives in CPU ram
	glGenBuffers(1, &VBO); //1 represents the number of buffers to generate, &VBO is the address of the buffer object name to be generated
	glBindBuffer(GL_ARRAY_BUFFER, VBO); //bind the buffer object to the GL_ARRAY_BUFFER target so that it can be used for vertex attribute data


	GLuint VAO; //cpu variable
	glGenVertexArrays(1, &VAO); //creates a VAO object and stores its ID in the VAO variable
	glBindVertexArray(VAO); // make it the current VAO



	//this here will copy the data from the CPU ram to the GPU ram so that it can be used for rendering
	glBufferData(GL_ARRAY_BUFFER,
		sizeof(vertices),
		vertices,//the data to be copied to the buffer object
		GL_STATIC_DRAW); //"I'm probably going to upload this once and draw it many times."

	glViewport(0, 0, 800, 600);

	std::cout << "GLAD initialized successfully!\n";

	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

	while (!glfwWindowShouldClose(window)
		){

		glfwPollEvents(); //poll events to handle user input and window events
		glClear(GL_COLOR_BUFFER_BIT); //clear back buffer to prepare for rendering the next frame
		glfwSwapBuffers(window); //swap the front and back buffers to display the rendered frame

	}

	glfwTerminate(); //clean up and terminate GLFW before exiting the program
	return 0;
}