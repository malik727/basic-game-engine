#include "Shader.h"

void Shader::initShader(const std::string& filepath)
{
    ShaderProgramCode codes = ParseShader(filepath);
    this->shaderID = CreateShader(codes.VertexShader, codes.FragmentShader);
}

void Shader::Bind()const
{
    glWrap(glUseProgram(shaderID));
}

void Shader::UnBind()const
{
    glWrap(glUseProgram(0));
}

int Shader::GetUniformLoc(const std::string& name)
{
    // Implement Shader Cache Here

    glWrap(int uniLoc = glGetUniformLocation(shaderID, name.c_str()));
    if(uniLoc == -1)
    {
        std::cout << "Warning! Uniform " << name << " Deosn't Exists." << std::endl;
    }
    return uniLoc;
}

void Shader::SetUniform1i(const std::string& name, int value)
{
    int uniLoc = GetUniformLoc(name);
    glWrap(glUniform1i(uniLoc, value));
}

void Shader::SetUniform4f(const std::string& name, float v1, float v2, float v3, float v4)
{
    int uniLoc = GetUniformLoc(name);
    glWrap(glUniform4f(uniLoc, v1, v2, v3, v4));
}
void Shader::SetUniformMatrix4fv(const std::string& name, const float *mat4, int count, bool transpose)
{
    int uniLoc = GetUniformLoc(name);
    glWrap(glUniformMatrix4fv(uniLoc, count, transpose, mat4));
}
unsigned int Shader::CompileShader(unsigned int type, const std::string &source)
{
    glWrap(unsigned int shaderID = glCreateShader(type));
    const char * src = source.c_str();
    glWrap(glShaderSource(shaderID, 1, &src, nullptr));
    glWrap(glCompileShader(shaderID));
    int compileResult;
    glWrap(glGetShaderiv(shaderID, GL_COMPILE_STATUS, &compileResult));
    // Handling Shader Errors
    if(!compileResult)
    {
        int errorLength;
        glWrap(glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &errorLength));
        char *errorMsg = new char[errorLength];
        glWrap(glGetShaderInfoLog(shaderID, errorLength, &errorLength, errorMsg));
        std::cout << "Failed to Compile " << (type == GL_VERTEX_SHADER ? "Vertex" : "Fragment") <<" Shader: " << std::endl;
        std::cout << errorMsg << std::endl;
        glDeleteShader(shaderID);
        delete[] errorMsg;
        return 0;
    }
    return shaderID;
}

ShaderProgramCode Shader::ParseShader(const std::string &filepath)
{
    std::fstream shaderFile;
    shaderFile.open(filepath, std::ios::in);
    if(!shaderFile.is_open())
    {
        std::cout << "Failed to load Shader file at \"" << filepath << "\"!" << std::endl;
    }
    std::string shaderType = "", vertexShader = "", fragmentShader = "";
    std::string line;
    while(getline(shaderFile, line))
    {
        if(line.find("#shader") != std::string::npos)
        {
            if(line.find("vertex") != std::string::npos)
            {
                shaderType = "vertex"; 
            }
            else if(line.find("fragment") != std::string::npos)
            {
                shaderType = "fragment"; 
            }
        }
        else
        {
            if(shaderType == "vertex")
            {
                vertexShader += line += "\n";
            }
            else if(shaderType == "fragment")
            {
                fragmentShader += line += "\n";
            }
        }
    }
    return {vertexShader, fragmentShader};
}

unsigned int Shader::CreateShader(const std::string &vertexShader, const std::string &fragmentShader)
{
    glWrap(unsigned int program = glCreateProgram());
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);
    glWrap(glAttachShader(program, vs));
    glWrap(glAttachShader(program, fs));
    glWrap(glLinkProgram(program));
    glWrap(glValidateProgram(program));
    glWrap(glDeleteShader(vs));
    glWrap(glDeleteShader(fs));
    return program;
}