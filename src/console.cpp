#include "console.hpp"
#include <iostream>

using namespace std;

float console::yAngle = 0.0;
float console::zAngle = 0.0;
unsigned int console::count = 0;
bool console::keys[1024] = {false};

bool console::Initialize()
{
    return true;
}

void console::Release()
{
}

void console::KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_Q && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
    if (key == GLFW_KEY_P && action == GLFW_PRESS) {
        count++;
    }
    if (key >= 0 && key < 1024)
    {
        if (action == GLFW_PRESS)
            keys[key] = true;
        else if (action == GLFW_RELEASE)
            keys[key] = false;
    }
}

void console::Movement(float deltaTime)
{
    deltaTime *= 50;
    // Camera controls
    if (keys[GLFW_KEY_W])
        yAngle += 1.0f * deltaTime;
    if (keys[GLFW_KEY_S])
        yAngle -= 1.0f * deltaTime;
    if (keys[GLFW_KEY_A])
        zAngle += 1.0f * deltaTime;
    if (keys[GLFW_KEY_D])
        zAngle -= 1.0f * deltaTime;

}
