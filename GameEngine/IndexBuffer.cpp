#include "IndexBuffer.h"

void IndexBuffer::Bind()const
{
    glWrap(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID));
}

void IndexBuffer::initBuffer(const unsigned int* data, unsigned int count)
{
    this->count = count;
    glWrap(glGenBuffers(1, &bufferID));
    glWrap(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID));
    glWrap(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));
}

void IndexBuffer::UnBind()const
{
    glWrap(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}

unsigned int IndexBuffer::GetCount()const
{
    return this->count;
}