#ifndef VERTEXARRAY_H
#define VERTEXARRAY_H

#include "VertexBuffer.h"
#include "VBSpecs.h"
#include "ErrorHandler.h"

class VertexArray
{
    private:
        unsigned int vertexArrayID;
    public:
        VertexArray()
        {
            
        }
        void initVertexArray();
        void Bind()const;
        void UnBind()const;
        void AddBuffer(const VertexBuffer& vbuffer, const VBSpecs& vbuffer_specs);
        ~VertexArray()
        {
            glWrap(glDeleteVertexArrays(1, &vertexArrayID));
        }
};

#endif