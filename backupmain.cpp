//#include <glad/gl.h>
//#include <GLFW/glfw3.h>
//#include<iostream>
//#include "../include/Vec2.h"
//#include "../include/Rectangle.h"
//#include "../include/Ball.h"
//#include "../include/Update.h"
//#include "../include/Collision.h"
//
//int main() {
//
//	if (!glfwInit())
//	{
//		std::cout << "Failed to initialize GLFW\n";
//		return -1;
//	}
//
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	GLFWwindow* window = glfwCreateWindow(
//		800,
//		600,
//		"Collision Detection",
//		nullptr,
//		nullptr
//	);
//
//	if (!window) {
//		std::cout << "Failed to create GLFW window\n";
//		glfwTerminate();
//		return -1;
//	}
//
//	glfwMakeContextCurrent(window); //make the opengl context current so that glad can load the function pointers for the current context
//
//
//	//initialize glad to load the opengl function pointers for the current context
//	if (!gladLoadGL(glfwGetProcAddress))
//	{
//		std::cout << "Failed to initialize GLAD\n";
//		glfwTerminate();
//		return -1;
//	}
//
//	float vertices[] =
//	{
//		0.3f, 0.8f, //first triangle
//		-0.3f, 0.8f,
//		-0.3f,  0.5f,
//
//		 0.3f, 0.8f,//second triangle
//		-0.3f, 0.5f,
//		 0.3f, 0.5f
//	};
//
//	GLuint VAO; //cpu variable
//	glGenVertexArrays(1, &VAO); //creates a VAO object and stores its ID in the VAO variable
//	glBindVertexArray(VAO); // make it the current VAO
//
//	GLuint VBO; //vbo lives in CPU ram
//	glGenBuffers(1, &VBO); //1 represents the number of buffers to generate, &VBO is the address of the buffer object name to be generated
//	glBindBuffer(GL_ARRAY_BUFFER, VBO); //bind the buffer object to the GL_ARRAY_BUFFER target so that it can be used for vertex attribute data
//
//	//this here will copy the data from the CPU ram to the GPU ram so that it can be used for rendering
//	glBufferData(GL_ARRAY_BUFFER,
//		sizeof(vertices),
//		vertices,//the data to be copied to the buffer object
//		GL_STATIC_DRAW); //"I'm probably going to upload this once and draw it many times."
//
//
//	glVertexAttribPointer(
//		0,
//		2,
//		GL_FLOAT,
//		GL_FALSE,
//		2 * sizeof(float),
//		(void*)0
//	);
//	glEnableVertexAttribArray(0); //enable the vertex attribute array at index 0
//
//	const char* vertexShaderSource = R"(
//
//     #version 460 core
//
//      layout(location = 0) in vec2 aPos;
//
//      void main() {
//       gl_Position = vec4(aPos, 0.0, 1.0);
//      }
//     )";
//
//
//	const char* fragmentShaderSource = R"(
//		#version 460 core
//		out vec4 FragColor;
//		void main(){
//		  FragColor = vec4(1.0, 0.5, 0.2, 1.0); 
//		} 
//		)";
//	//FragColor = vec4(1.0, 0.5, 0.2, 1.0); rgba 
//
//	// 1. Create a vertex shader 2. Provide the source code to the shader 3. Compile the shader
//	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER); //create a vertex shader object and return its ID
//
//	glShaderSource(vertexShader,
//		1, //number of strings in the array
//		&vertexShaderSource, // 
//		nullptr
//	);
//	glCompileShader(vertexShader); //compile the shader source code
//
//	GLint success; //why not bool? because glGetShaderiv expects a GLuint pointer as the second argument, so we use GLuint instead of bool (opengl defined integer types GLint is expected in return value of glGetShaderiv)
//	char infoLog[512];
//
//	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success); //check if the shader compiled successfully)
//
//	if (!success) {
//		glGetShaderInfoLog(
//			vertexShader,
//			512,
//			nullptr,
//			infoLog
//		);
//
//		std::cout << infoLog << std::endl;
//	}
//
//	GLuint fragmentShader =
//		glCreateShader(GL_FRAGMENT_SHADER);
//
//	glShaderSource(
//		fragmentShader,
//		1,
//		&fragmentShaderSource,
//		nullptr
//	);
//
//	glCompileShader(fragmentShader);
//
//
//	glGetShaderiv(
//		fragmentShader,
//		GL_COMPILE_STATUS,
//		&success
//	);
//
//	if (!success)
//	{
//		glGetShaderInfoLog(
//			fragmentShader,
//			512,
//			nullptr,
//			infoLog
//		);
//
//		std::cout << infoLog << std::endl;
//	}
//
//	//create program object and link the shaders to it
//
//	GLuint shaderProgram = glCreateProgram(); //creates a shader object program and returns its ID Gluint
//
//	glAttachShader(shaderProgram, vertexShader); //attach the vertex shader to the program object
//	glAttachShader(shaderProgram, fragmentShader); //attach the fragment shader to the program object
//
//	glLinkProgram(shaderProgram); //link the program object to the shaders
//
//	glGetProgramiv(
//		shaderProgram,
//		GL_LINK_STATUS,
//		&success
//	);
//
//	if (!success) {
//		glGetProgramInfoLog(
//			shaderProgram,
//			512,
//			nullptr,
//			infoLog
//		);
//		std::cout << infoLog << std::endl;
//	}
//	//glUseProgram(shaderProgram); //don't miss this else black screen will be displayed because the program object is not being used to render the triangle
//	//glDrawArrays(GL_TRIANGLES, 0, 3); //gl-trianlges means interpret the vertices as triangles. 0 means start from the first vertex and 3 means draw 3 vertices (1 triangle)
//
//
//	glViewport(0, 0, 800, 600);
//
//	std::cout << "GLAD initialized successfully!\n";
//
//	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//
//	while (!glfwWindowShouldClose(window)
//		) {
//
//		glfwPollEvents(); //poll events to handle user input and window events
//		glClear(GL_COLOR_BUFFER_BIT); //clear back buffer to prepare for rendering the next frame
//		glUseProgram(shaderProgram);
//		glBindVertexArray(VAO); //bind the VAO to use the vertex attribute data stored in it //1. first bind was to set and bin to configure vao 2. here this VAO means bind and use the vertex attribute data stored in it for rendering
//		glDrawArrays(GL_TRIANGLES, 0, 6);
//		//we would use 3 in place of 6 if we were to draw only one triangle, but since we are drawing two triangles to form a rectangle, we use 6 instead of 3
//		//draw the triangle using the vertex attribute data stored in the VAO
//		glfwSwapBuffers(window); //swap the front and back buffers to display the rendered frame
//	}
//
//	glfwTerminate(); //clean up and terminate GLFW before exiting the program
//	return 0;
//}

//collision code  ------------- ||---------------------------
//#include "../include/Collision.h"
//#include<algorithm>
//
//bool CheckCollision(const Ball& ball, const Rectangle& rect
//) {
//	Vec2 center{ ball.position.x + ball.radius,
//				 ball.position.y + ball.radius
//	}; //the center of the ball because the position is top left and we add the radius to both x and y to get the center
//
//	//findind the half of the rectangle's width and height to get the half extents
//	Vec2 half_extents{ rect.size.x / 2.0f, rect.size.y / 2.0f };
//
//	//finding the center of the rectangle by adding the half extents to the position of the rectangle
//	Vec2 rectangle_center{ rect.position.x + half_extents.x
//				 , rect.position.y + half_extents.y };
//
//	Vec2 difference = center - rectangle_center; //finding the difference between the center of the ball and the center of the rectangle
//
//	//Vec2 clamped = { std::max(-half_extents.x, std::min(difference.x, half_extents.x)),
//	//					std::max(-half_extents.y, std::min(difference.y, half_extents.y)) }; //clamping the difference to the half extents of the rectangle
//
//	Vec2 clamped{
//		std::clamp(difference.x,-half_extents.x,half_extents.x),
//		std::clamp(difference.y,-half_extents.y,half_extents.y)
//	};
//
//	Vec2 closest = rectangle_center + clamped; //finding the closest point on the rectangle to the center of the ball
//
//	Vec2 distance = closest - center; //finding the distance between the closest point and the center of the ball
//
//	float distance_squared =
//		distance.x * distance.x +
//		distance.y * distance.y; //finding the squared distance
//
//	return distance_squared <= ball.radius * ball.radius; //checking if the squared distance is less than the squared radius of the ball, also touching is colliding
//}