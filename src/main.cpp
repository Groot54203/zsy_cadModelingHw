#include "main.hpp"

#define GL_SILENCE_DEPRECATION
#include <iostream>
#include <algorithm>
#include "console.hpp"
#include "SolidModeling.hpp"

using namespace std;
using namespace glm;

int main()
{
    // Init GLFW
    InitGLFW();
    Initconsole();
    // Enable settings
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.801, 0.801, 0.703, 1.0);

    // Init FPS Var
    std::cout << "Program Running..." << endl;
    std::cout << "========================================" << endl;


    vector<Solid*> solidList;
    Solid *solidC = CreateC();
    solidList.push_back(solidC);

    //Solid *solidA = CreateA();
    //solidList.push_back(solidA);

    Solid *solidZero = CreateZero();
    solidList.push_back(solidZero);

    Solid *solidEight = CreateEight();
    solidList.push_back(solidEight);

    GLfloat deltaTime = 0, currentTime = 0;
    GLfloat startTime = glfwGetTime();
    GLfloat lastTime = glfwGetTime();
    while (!glfwWindowShouldClose(window))
    {
        Solid *drawSolid = solidList[console::count % solidList.size()];
        glfwPollEvents();
        GLfloat newTime = glfwGetTime();
        console::Movement(newTime - lastTime);
        lastTime = newTime;

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
        glViewport(0, 0, SCREEN_SIZE.x , SCREEN_SIZE.y*2);
        
        // Perspective
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        gluPerspective(45.0f, SCREEN_SIZE.x / 2.0 / SCREEN_SIZE.y, 0.1f, 100.0f);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity(); // Reset the model-view matrix
        glTranslatef(0.0f, 0.0f, -10.0f);

        glRotatef(console::zAngle, 0.0f, 1.0f, 0.0f);
        glRotatef(console::yAngle, 1.0f, 0.0f, 1.0f);

        glRotatef(180.0, 0.0f, 1.0f, 0.0f);
        glRotatef(90.0, 1.0f, 0.0f, 0.0f);

        DrawSolid(drawSolid);

        glViewport(SCREEN_SIZE.x , 0, SCREEN_SIZE.x , SCREEN_SIZE.y*2);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        gluPerspective(45.0f, SCREEN_SIZE.x / 2.0 / SCREEN_SIZE.y, 0.1f, 100.0f);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity(); // Reset the model-view matrix
        glTranslatef(0.0f, 0.0f, -10.0f);
        

        glRotatef(console::zAngle, 0.0f, 1.0f, 0.0f);
        glRotatef(console::yAngle, 1.0f, 0.0f, 1.0f);

        glRotatef(180.0, 0.0f, 1.0f, 0.0f);
        glRotatef(90.0, 1.0f, 0.0f, 0.0f);
        DrawSolid(drawSolid, true);

        glfwSwapBuffers(window);
    }

    Releaseconsole();

    glfwTerminate();
    return 0;
}

int InitGLFW()
{
    /* Initialize the library */
    if (!glfwInit())
    {
        return -1;
    }

    // glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // glfwWindowHint (GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    // glfwWindowHint (GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
    // Create window
    window = glfwCreateWindow(SCREEN_SIZE.x, SCREEN_SIZE.y, "cadModelingHw", nullptr, nullptr);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    // Windowed
    glfwMakeContextCurrent(window);

    // Print out some info about the graphics drivers
    std::cout << "========================================" << endl;
    std::cout << "旋转控制：WSAD" << std::endl;
    std::cout << "切换实体模型：P" << std::endl;
    std::cout << "终止程序：Q" << std::endl;

    return 0;
}

void Initconsole()
{
    if (!console::Initialize())
    {
        std::cout << "Unable to initialize camera!" << endl;
    }

    glfwSetKeyCallback(window, console::KeyCallback);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void Releaseconsole()
{
    console::Release();
}
