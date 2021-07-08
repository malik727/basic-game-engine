#include "MainEngine.h"

void MainEngine::Draw(const VertexArray& v_array, const IndexBuffer& i_buffer, const Shader& shader, int size, bool indexed = false)const
{
    glWrap(glClearColor(0.529f, 0.807f, 0.921f, 1.0f));
    v_array.Bind();
    shader.Bind();
    if(indexed == true)
    {
        i_buffer.Bind();
        glWrap(glDrawElements(GL_TRIANGLES, i_buffer.GetCount(), GL_UNSIGNED_INT, nullptr));
    }
    else
    {
        glWrap(glDrawArrays(GL_TRIANGLES, 0, size));
    }
    // v_array.UnBind();
    // shader.UnBind();
    // i_buffer.UnBind();
}

void MainEngine::ClearScreen()const
{
    glWrap(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
}

void MainEngine::displayMetaData()const
{
    std::cout << "\n|----------------------- Meta Info ------------------------|" << std::endl;
    std::cout << "| Renderer: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "| OpenGL:   v" << glGetString(GL_VERSION) << std::endl;
    std::cout << "| GLFW:     v" << glfwGetVersionString() << std::endl;
    std::cout << "| Vendor:   " << glGetString(GL_VENDOR) << std::endl;
    std::cout << "|----------------------------------------------------------|\n" << std::endl;
}

void MainEngine::handleKeyboardInput(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if(action == GLFW_PRESS)
    {
        // std::cout<< "Key Pressed! " << key << std::endl;
    }
    else if(action == GLFW_REPEAT)
    {
        // std::cout<< "Key Held Down!" << key << std::endl;
    }
}
void MainEngine::handleMouseClick(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
    {
        // std::cout << "Mouse Right Button Clicked!" <<std::endl;
        // std::cout << "X-Axis: " << cursorXPos << std::endl;
        // std::cout << "Y-Axis: " << cursorYPos << std::endl;
    }
    else if(button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
    {
        // std::cout << "Mouse Left Button Clicked!" <<std::endl;
        // std::cout << "X-Axis: " << cursorXPos << std::endl;
        // std::cout << "Y-Axis: " << cursorYPos << std::endl;
    }
}
void MainEngine::handleMousePosition(GLFWwindow* window, double xpos, double ypos)
{
    cursorXPos = xpos;
    cursorYPos = ypos;
}

void MainEngine::handleEngineCameraInit()
{
    camView.initCam(winWidth, winHeight);
}

void MainEngine::handleCamInputs(GLFWwindow* gameWindow)
{
    camView.camInputs(gameWindow);
}

void MainEngine::handleCamMatrix(float FOVdeg, float nearPlane, float farPlane, Shader& shader, const std::string uniform)
{
    camView.camMatrix(FOVdeg, nearPlane, farPlane, shader, uniform);
}