#include "ErrorHandler.h"

void GLClearError()
{
    while(glGetError());
}

bool GLLogError(const char* functionName, const char* fileName, const int lineNum)
{
    if(unsigned int errorCode = glGetError())
    {
        std::cout << "\n***** Fatal Error Occurred *****" << std::endl;
        std::cout << "Error Source: [OpenGL]" << std::endl;
        std::cout << "Error Code: 0x" << std::setfill('0') << std::setw(4) << std::hex << errorCode << std::dec << std::endl;
        std::cout << "Error Function: " << functionName << std::endl;
        std::cout << "Error Line: " << lineNum << std::endl;
        std::cout << "Error File: " << fileName << std::endl;
        std::cout << "********************************\n" << std::endl;
        return false;
    }
    return true;
}