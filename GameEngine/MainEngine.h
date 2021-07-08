#ifndef MAINENGINE_H
#define MAINENGINE_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "vendor/glm/glm.hpp"
#include "vendor/glm/gtc/matrix_transform.hpp"
#include "vendor/glm/gtc/type_ptr.hpp"
#include "vendor/glm/gtx/rotate_vector.hpp"
#include "vendor/glm/gtx/vector_angle.hpp"
#include "ErrorHandler.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "Texture.h"
#include "EngineCamera.h"
#include "OBJLoader.h"

class MainEngine 
{
    private:
        int winWidth;
        int winHeight;
        static double cursorXPos;
        static double cursorYPos;
        EngineCamera camView;

    public:
        MainEngine()
        {
            this->winWidth = 0;
            this->winHeight = 0;
        }
        MainEngine(int width, int height)
        {
            this->winWidth = width;
            this->winHeight = height;
        }
        void Draw(const VertexArray& v_array, const IndexBuffer& i_buffer, const Shader& shader, int size, bool indexed)const;
        void ClearScreen()const;
        void displayMetaData()const;
        static void handleKeyboardInput(GLFWwindow* window, int key, int scancode, int action, int mods);
        static void handleMouseClick(GLFWwindow* window, int button, int action, int mods);
        static void handleMousePosition(GLFWwindow* window, double xpos, double ypos);
        void handleEngineCameraInit();
        void handleCamInputs(GLFWwindow* gameWindow);
        void handleCamMatrix(float FOVdeg, float nearPlane, float farPlane, Shader& shader, const std::string uniform);
        ~MainEngine()
        {
            
        }
};

#endif