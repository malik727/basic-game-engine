#ifndef OBJLOADER_H
#define OBJLOADER_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "vendor/glm/glm.hpp"
#include "vendor/glm/gtc/matrix_transform.hpp"
#include "vendor/glm/gtc/type_ptr.hpp"
#include "vendor/glm/gtx/rotate_vector.hpp"
#include "vendor/glm/gtx/vector_angle.hpp"
#include "ErrorHandler.h"

class OBJLoader
{
    private:
        std::string objFilePath;
        std::string mtlFilePath;
        std::vector <glm::vec3> vertices;
        std::vector <glm::vec3> colorCoords;
        std::vector <glm::vec4> faces;

    public:
        OBJLoader(const std::string& objfile, const std::string& mtlfile)
        {
            this->objFilePath = objfile;
            this->mtlFilePath = mtlfile;
        }
        void loadModel();
        float* generateLudoVertices(int& size);
        float* generateTokenVertices(int& size);
        float* generateDiceVertices(int& size);
        std::vector <glm::vec3> getVertices()const;
        std::vector <glm::vec3> getColorCoords()const;
};


#endif