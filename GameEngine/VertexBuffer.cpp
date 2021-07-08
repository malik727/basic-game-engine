#include "VertexBuffer.h"

void VertexBuffer::Bind()const
{
    glWrap(glBindBuffer(GL_ARRAY_BUFFER, bufferID));
}

void VertexBuffer::initBuffer(const void* data, unsigned int size)
{
    glWrap(glGenBuffers(1, &bufferID));
    glWrap(glBindBuffer(GL_ARRAY_BUFFER, bufferID));
    glWrap(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}

void VertexBuffer::UnBind()const
{
    glWrap(glBindBuffer(GL_ARRAY_BUFFER, 0));
}