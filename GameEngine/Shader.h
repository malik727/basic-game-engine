#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <iostream>
#include <fstream>
#include "ErrorHandler.h"

struct ShaderProgramCode
{
    std::string VertexShader;
    std::string FragmentShader;
};

class Shader 
{
    private:
        unsigned int shaderID;

    public:
        Shader()
        {
            this->shaderID = 0;
        }
        Shader(const std::string& filepath):shaderID(0)
        {
            ShaderProgramCode codes = ParseShader(filepath);
            shaderID = CreateShader(codes.VertexShader, codes.FragmentShader);
        }
        void Bind()const;
        void UnBind()const;
        void initShader(const std::string& filepath);
        void SetUniform4f(const std::string& name, float v1, float v2, float v3, float v4);
        void SetUniform1i(const std::string& name, int value);
        void SetUniformMatrix4fv(const std::string& name, const float *mat4, int count = 1, bool transpose = false);
        int GetUniformLoc(const std::string& name);
        unsigned int CompileShader(unsigned int type, const std::string &source);
        unsigned int CreateShader(const std::string &vertexShader, const std::string &fragmentShader);
        ShaderProgramCode ParseShader(const std::string &filepath);
        ~Shader()
        {
            glWrap(glDeleteProgram(shaderID));
        }
};

#endif