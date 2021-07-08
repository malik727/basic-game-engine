#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

// Including OpenGL Libraries
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <iomanip>
#include <signal.h>

// Defining Macros to get detailed information regarding OpenGL errors and terminate execution if error occurs
#define ASSERT(GL_ERROR_CUSTOM) if (!(GL_ERROR_CUSTOM)) raise(SIGTRAP);
#define glWrap(GL_ERROR_CUSTOM) GLClearError(); GL_ERROR_CUSTOM; ASSERT(GLLogError(#GL_ERROR_CUSTOM, __FILE__, __LINE__))

// these functions are used in custom error handling
void GLClearError();
bool GLLogError(const char* functionName, const char* fileName, const int lineNum);

#endif