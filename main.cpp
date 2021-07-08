// Including OpenGL Libraries
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// The Engine Mode Macro; 0 indicates Release Mode & 1 indicates Debug Mode
#ifndef ENGINE_MODE
    #define ENGINE_MODE 1
#endif

// Including Program Libraries
#include <iostream>
#include <string>
#include <fstream>
#include "GameEngine/MainEngine.h"

double MainEngine::cursorXPos;
double MainEngine::cursorYPos;

int main()
{
    // Initializing GLFW
    if(glfwInit() != GLFW_TRUE)
    {
        std::cout << "Failed to Initialize GLFW!" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Setting OpenGL Version to Use
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Creating the Window
    GLint SCR_WIDTH = 900, SCR_HEIGHT = 750;
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Engine Window", NULL, NULL);
    glfwMakeContextCurrent(window);

    // Checking if Window Created Successfully
    if(window == NULL)
    {
        std::cout << "Failed to create window!" << std::endl;
        glfwDestroyWindow(window);
        glfwTerminate();
        return -2;
    }

    // Cross Platform Support to Pull OpenGL Latest Functions
    if(glewInit() != GLEW_OK)
    {
        std::cout << "Failed to Initialize GLEW!" << std::endl;
    }

    // Setting GLFW to use Device Compatible FPS
    glfwSwapInterval(1);

    // Configuring Buffers
    int Buffer_Width, Buffer_Height;
    glfwGetFramebufferSize(window, &Buffer_Width, &Buffer_Height);

    // FPS Record Variables
    double previousTime = glfwGetTime();
    int fps = 0;
    std::string winTitle = "";

    // Setting Viewport
    glViewport(0, 0, Buffer_Width, Buffer_Height);

    // Handling Key Board Input
    glfwSetKeyCallback(window, MainEngine::handleKeyboardInput);

    // Setting Mouse Controls
    glfwSetMouseButtonCallback(window, MainEngine::handleMouseClick);
    glfwSetCursorPosCallback(window, MainEngine::handleMousePosition);

    // Enabling some default configs
    glWrap(glEnable(GL_BLEND));
    glWrap(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
	glWrap(glEnable(GL_DEPTH_TEST));

    while(!glfwWindowShouldClose(window))
    {   
        // Te keep track of FPS if game is in Debug Mode
        if(ENGINE_MODE == 1)
        {
            double currentTime = glfwGetTime();
            fps++;
            if (currentTime - previousTime >= 1.0)
            {
                winTitle = "Game Engine [FPS: "+std::to_string(fps)+"]"+" [MSPF: "+std::to_string(1000.0/double(fps))+"]";
                glfwSetWindowTitle(window, winTitle.c_str());
                fps = 0;
                previousTime = currentTime;
            }
        }

        // Render your engine here
        
        glWrap(glfwSwapBuffers(window));
        glWrap(glfwPollEvents());    
    }
    glfwTerminate();
    return 0;
}