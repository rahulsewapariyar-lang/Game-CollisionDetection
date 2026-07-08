#pragma once
#include<glad/gl.h>
#include<GLFW/glfw3.h>
struct GLFWwindow;

GLFWwindow* InitWindow(
	int width,
	int height,
	const char* title,
	GLFWmonitor* monitor = nullptr,
	GLFWwindow* share = nullptr
);