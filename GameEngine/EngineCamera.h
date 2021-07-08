#ifndef ENGINECAMERA_H
#define ENGINECAMERA_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "vendor/glm/glm.hpp"
#include "vendor/glm/gtc/matrix_transform.hpp"
#include "vendor/glm/gtc/type_ptr.hpp"
#include "vendor/glm/gtx/rotate_vector.hpp"
#include "vendor/glm/gtx/vector_angle.hpp"
#include "Shader.h"

class EngineCamera
{
    private:
        int width;
        int height;
        glm::vec3 rotationAxis;
        glm::vec3 tiltAxis;
        glm::vec3 camPosition;
        glm::vec3 camOrientation;
        float rotation;
        glm::mat4 view;
        glm::mat4 projection;
        glm::mat4 model;

    public:
        EngineCamera()
        {
            
        };
        void initCam(int width, int height);
        void camMatrix(float FOVdeg, float nearPlane, float farPlane, Shader& shader, const std::string& uniform);
        void camInputs(GLFWwindow* gameWindow);
};

#endif