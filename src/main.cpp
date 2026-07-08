#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include<iostream>
#include "../include/Vec2.h"
#include "../include/Rectangle.h"
#include "../include/Ball.h"
#include "../include/Update.h"
#include "../include/Collision.h"
#include "../include/Window.h"
#include "../include/Mesh.h"
#include "../include/Shader.h"
#include "../include/Renderer.h"

int main() {

	GLFWwindow* window = InitWindow(800,600,"Collision Detection");

	const char* vertexShaderSource = R"(

     #version 460 core

      layout(location = 0) in vec2 aPos;

      void main() {
       gl_Position = vec4(aPos, 0.0, 1.0);
      }
     )";


	const char* fragmentShaderSource = R"(
		#version 460 core
		out vec4 FragColor;
		void main(){
		  FragColor = vec4(1.0, 0.5, 0.2, 1.0); 
		} 
		)";

	GLuint shaderProgram = CreateShaderProgram(
		vertexShaderSource,
		fragmentShaderSource
	);



	float vertices[] =
	{
		0.3f, 0.8f, //first triangle
		-0.3f, 0.8f,
		-0.3f,  0.5f,

		 0.3f, 0.8f,//second triangle
	    -0.3f, 0.5f,
	     0.3f, 0.5f
	};

	Mesh rectangle = CreateMesh(vertices, sizeof(vertices), 2);

	while (!glfwWindowShouldClose(window)
		){
		Clear(0.2f, 0.3f, 0.3f, 1.0f); //clear the screen with a specific color
		glfwPollEvents(); //poll events to handle user input and window events
		Render(rectangle, shaderProgram);
		glfwSwapBuffers(window); //swap the front and back buffers to display the rendered frame
	}
	
	glfwTerminate(); //clean up and terminate GLFW before exiting the program
	return 0;
}