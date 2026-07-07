#include <GLFW/glfw3.h>
#include<iostream>

void TESTGLFW() {
    if (!glfwInit())
    {
        std::cout << "Failed to initialize GLFW\n";
        return;
    }

    std::cout << "GLFW initialized successfully!\n";

    glfwTerminate();
}