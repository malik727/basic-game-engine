#ifndef INDEXBUFFER_H
#define INDEXBUFFER_H

#include "ErrorHandler.h"

class IndexBuffer 
{
    private:
        unsigned int bufferID;
        unsigned int count;

    public:
        IndexBuffer()
        {
            this->bufferID = 0;
            this->count = 0;
        }
        IndexBuffer(const unsigned int* data, unsigned int count):count(count)
        {
            glWrap(glGenBuffers(1, &bufferID));
            glWrap(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID));
            glWrap(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));
        }
        void initBuffer(const unsigned int* data, unsigned int count);
        void Bind() const;
        void UnBind() const;
        unsigned int GetCount() const;
        ~IndexBuffer()
        {
            glWrap(glDeleteBuffers(1, &bufferID));
        }
};

#endif