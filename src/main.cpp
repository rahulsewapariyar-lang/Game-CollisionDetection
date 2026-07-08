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
      
      uniform vec2 uOffset;
      uniform vec2 uScale;

      void main() {
       vec2 position = aPos * uScale + uOffset;
       gl_Position = vec4(position, 0.0, 1.0);
      }
     )"; //offset move the object, uscale resize the object


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
	std::cout << "shaderProgram = "
		<< shaderProgram
		<< '\n';

	float vertices[] =
	{
		 -0.5f,  0.5f,
	    -0.5f, -0.5f,
	     0.5f, -0.5f,

	    -0.5f,  0.5f,
	     0.5f, -0.5f,
	     0.5f,  0.5f
	};


	Mesh rectangleMesh = CreateMesh(vertices, sizeof(vertices), 2);
	Mesh ballMesh = CreateCircleMesh(0.5f,64);

	Rectangle rect;
	rect.transform.position = {0.4f,0.0f};
	rect.transform.scale = { 0.3f,0.2f };

	Ball ball;
	ball.transform.position = {0.0f,-0.8f};
	ball.transform.scale = { 0.1f,0.1f };


	ball.velocity = { 0.5f,0.0f };
	ball.radius = 0.05f;


	float speed = 0.1f;
	float rectHalfHeight = rect.transform.scale.y *0.5f;
	float rectHalfWidth = rect.transform.scale.x * 0.5f;

	float ballHalfHeight =    ball.transform.scale.y *0.5f;
	float ballHalfWidth = ball.transform.scale.x * 0.5f;	

    float LastFrame = 0.0f;
	while (!glfwWindowShouldClose(window)
		){
    	float CurrentFrame = glfwGetTime();
    	float deltaTime = CurrentFrame - LastFrame;
    	LastFrame = CurrentFrame;
		Clear(0.2f, 0.3f, 0.3f, 1.0f); //clear the screen with a specific color
		glfwPollEvents(); //poll events to handle user input and window events

		rect.transform.position.x += speed * deltaTime;
		ball.transform.position.x += ball.velocity.x * deltaTime;
		ball.transform.position.y += ball.velocity.y * deltaTime;

		if (rect.transform.position.x + rectHalfWidth > 1.0f){
			speed = -speed;
			rect.transform.position.x = 1.0f - rectHalfWidth;
		}
		if (rect.transform.position.x - rectHalfWidth < -1.0f) {
			rect.transform.position.x = -1.0f + rectHalfWidth;
			speed = -speed;
		}
		if (ball.transform.position.x + ballHalfWidth > 1.0f ||
			ball.transform.position.x - ballHalfWidth < -1.0f)
		{
			ball.velocity.x = -ball.velocity.x;
		}
		glUseProgram(shaderProgram);
		Render(rectangleMesh, shaderProgram,rect.transform);
		Render(ballMesh, shaderProgram, ball.transform);
		glfwSwapBuffers(window); //swap the front and back buffers to display the rendered frame
	}	
	
	glfwTerminate(); //clean up and terminate GLFW before exiting the program
	return 0;
}