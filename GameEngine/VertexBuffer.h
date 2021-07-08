#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H

#include "ErrorHandler.h"

class VertexBuffer 
{
    private:
        unsigned int bufferID;

    public:
        VertexBuffer()
        {
            this->bufferID = 0;
        }
        VertexBuffer(const void* data, unsigned int size)
        {
            glWrap(glGenBuffers(1, &bufferID));
            glWrap(glBindBuffer(GL_ARRAY_BUFFER, bufferID));
            glWrap(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
        }
        void initBuffer(const void* data, unsigned int size);
        void Bind()const;
        void UnBind()const;
        ~VertexBuffer()
        {
            glWrap(glDeleteBuffers(1, &bufferID));
        }
};

#endif