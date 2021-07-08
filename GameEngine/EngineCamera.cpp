#include "EngineCamera.h"


void EngineCamera::camMatrix(float FOVdeg, float nearPlane, float farPlane, Shader& shader, const std::string& uniform)
{
    view = glm::lookAt(camPosition, camOrientation, tiltAxis);
	projection = glm::perspective(glm::radians(45.0f), (float)width / height, 0.1f, 100.0f);
    shader.SetUniformMatrix4fv(uniform, glm::value_ptr(projection * view * model), 1, false);
}

void EngineCamera::initCam(int width, int height)
{
    this->width = width;
    this->height = height;
    rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
    tiltAxis = glm::vec3(0.0f, 0.0f, 1.0f);
    rotation = 0.0f;
    view = glm::mat4(1.0f);
    projection = glm::mat4(1.0f);
    model = glm::mat4(1.0f);
    camPosition = glm::vec3(0.0f, -1.2f, 0.8f);
    camOrientation = glm::vec3(0.0f, 1.0f, -1.0f);
}

void EngineCamera::camInputs(GLFWwindow* gameWindow)
{
    // Left Arrow Key
	if (glfwGetKey(gameWindow, 263) == GLFW_PRESS)
	{
        model = glm::mat4(1.0f);
        rotation += 1.5f;
        model = glm::rotate(model, glm::radians(-rotation), rotationAxis);
        std::cout << "Tilt Axis: " << tiltAxis.x << ", " << tiltAxis.y << ", " << tiltAxis.z << std::endl; 
        std::cout << "Cam Position: " << camPosition.x << ", " << camPosition.y << ", " << camPosition.z << std::endl; 
        std::cout << "Cam Orientation: " << camOrientation.x << ", " << camOrientation.y << ", " << camOrientation.z << std::endl; 
	}
    // Right Arrow Key
	if (glfwGetKey(gameWindow, 262) == GLFW_PRESS)
	{
        model = glm::mat4(1.0f);
        rotation -= 1.5f;
        model = glm::rotate(model, glm::radians(-rotation), rotationAxis);
        std::cout << "Tilt Axis: " << tiltAxis.x << ", " << tiltAxis.y << ", " << tiltAxis.z << std::endl; 
        std::cout << "Cam Position: " << camPosition.x << ", " << camPosition.y << ", " << camPosition.z << std::endl; 
        std::cout << "Cam Orientation: " << camOrientation.x << ", " << camOrientation.y << ", " << camOrientation.z << std::endl; 
	}
    // Top Arrow Key
    if (glfwGetKey(gameWindow, 265) == GLFW_PRESS)
	{
        camPosition += 0.05f * camOrientation;
        std::cout << "Tilt Axis: " << tiltAxis.x << ", " << tiltAxis.y << ", " << tiltAxis.z << std::endl; 
        std::cout << "Cam Position: " << camPosition.x << ", " << camPosition.y << ", " << camPosition.z << std::endl; 
        std::cout << "Cam Orientation: " << camOrientation.x << ", " << camOrientation.y << ", " << camOrientation.z << std::endl; 
	}
    // Bottom Arrow Key
	if (glfwGetKey(gameWindow, 264) == GLFW_PRESS)
	{
        camPosition += 0.05f * -camOrientation;
        std::cout << "Tilt Axis: " << tiltAxis.x << ", " << tiltAxis.y << ", " << tiltAxis.z << std::endl; 
        std::cout << "Cam Position: " << camPosition.x << ", " << camPosition.y << ", " << camPosition.z << std::endl; 
        std::cout << "Cam Orientation: " << camOrientation.x << ", " << camOrientation.y << ", " << camOrientation.z << std::endl; 
	}
    // Plus Key
    if(glfwGetKey(gameWindow, 61) == GLFW_PRESS)
    {
        camPosition += 0.05f * tiltAxis;
        std::cout << "Tilt Axis: " << tiltAxis.x << ", " << tiltAxis.y << ", " << tiltAxis.z << std::endl; 
        std::cout << "Cam Position: " << camPosition.x << ", " << camPosition.y << ", " << camPosition.z << std::endl; 
        std::cout << "Cam Orientation: " << camOrientation.x << ", " << camOrientation.y << ", " << camOrientation.z << std::endl; 
    }
    // Minus Key
    if(glfwGetKey(gameWindow, 45) == GLFW_PRESS)
    {
        camPosition += 0.05f * -tiltAxis;
        std::cout << "Tilt Axis: " << tiltAxis.x << ", " << tiltAxis.y << ", " << tiltAxis.z << std::endl; 
        std::cout << "Cam Position: " << camPosition.x << ", " << camPosition.y << ", " << camPosition.z << std::endl; 
        std::cout << "Cam Orientation: " << camOrientation.x << ", " << camOrientation.y << ", " << camOrientation.z << std::endl; 
    }

}