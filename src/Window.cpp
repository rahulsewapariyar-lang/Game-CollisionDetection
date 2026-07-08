#include "../include/Window.h"
#include<iostream>

GLFWwindow* InitWindow(
    int width,
    int height,
    const char* title,
	GLFWmonitor* monitor,
	GLFWwindow* share
)
{
    
    if (!glfwInit())
    {
        std::cout << "Failed to initialize GLFW\n";
        return nullptr;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window =
        glfwCreateWindow(
            800,
            600,
            "Collision Detection",
            nullptr,
            nullptr
        );

    if (!window)
    {
        std::cout << "Failed to create window\n";
        glfwTerminate();
        return nullptr;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGL(glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD\n";
        glfwTerminate();
        return nullptr;
    }
    glViewport(0, 0, width, height);
    return window;
}